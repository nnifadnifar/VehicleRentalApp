#include "ProductView.h"
#include "../utils/idgenerator.h"
#include <QMessageBox>
#include <QInputDialog>

ProductView::ProductView(QWidget* parent, VehicleController* vehicleController)
    : QWidget(parent)
    , m_vehicleController(vehicleController)
    , m_table(nullptr)
{
}

void ProductView::setupUi(QTableWidget* table,
                          QLineEdit* searchEdit,
                          QComboBox* filterType,
                          QComboBox* filterAvailability,
                          QPushButton* btnAdd,
                          QPushButton* btnEdit,
                          QPushButton* btnDelete)
{
    m_table = table;
    m_searchEdit = searchEdit;
    m_filterType = filterType;
    m_filterAvailability = filterAvailability;
    m_btnAdd = btnAdd;
    m_btnEdit = btnEdit;
    m_btnDelete = btnDelete;

    // Connect signals
    connect(m_btnAdd, &QPushButton::clicked, this, &ProductView::onAddVehicle);
    connect(m_btnEdit, &QPushButton::clicked, this, &ProductView::onEditVehicle);
    connect(m_btnDelete, &QPushButton::clicked, this, &ProductView::onDeleteVehicle);
    connect(m_searchEdit, &QLineEdit::textChanged, this, &ProductView::onSearchVehicle);
    connect(m_filterType, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ProductView::onFilterType);
    connect(m_filterAvailability, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ProductView::onFilterAvailability);
}

void ProductView::loadData() {
    loadVehiclesTable();
}

void ProductView::refresh() {
    loadVehiclesTable();
}

void ProductView::loadVehiclesTable() {
    if (!m_table) return;

    m_table->setRowCount(0);
    auto vehicles = m_vehicleController->getAll();

    for (size_t i = 0; i < vehicles.size(); ++i) {
        const auto* vehicle = vehicles[i];
        m_table->insertRow(i);

        m_table->setItem(i, 0, new QTableWidgetItem(QString::number(vehicle->getId())));
        m_table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(vehicle->getVehicleType())));
        m_table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(vehicle->getBrand())));
        m_table->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(vehicle->getModel())));
        m_table->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(vehicle->getExtraField())));
        m_table->setItem(i, 5, new QTableWidgetItem(
                                   QString("Rp %L1").arg(vehicle->getDailyRate(), 0, 'f', 0)
                                   ));
        m_table->setItem(i, 6, new QTableWidgetItem(
                                   vehicle->isAvailable() ? "Available" : "Rented"
                                   ));
    }

    applyFilters();
}

void ProductView::applyFilters() {
    if (!m_table) return;

    QString typeFilter = m_filterType->currentText();
    QString availFilter = m_filterAvailability->currentText();
    QString searchText = m_searchEdit->text();

    for (int i = 0; i < m_table->rowCount(); ++i) {
        bool visible = true;

        // Type filter
        if (typeFilter != "All Types") {
            QString type = m_table->item(i, 1)->text();
            if (!type.contains(typeFilter, Qt::CaseInsensitive)) {
                visible = false;
            }
        }

        // Availability filter
        if (visible && availFilter != "All Status") {
            QString status = m_table->item(i, 6)->text();
            if (status != availFilter) {
                visible = false;
            }
        }

        // Search filter
        if (visible && !searchText.isEmpty()) {
            bool match = false;
            for (int j = 0; j < m_table->columnCount(); ++j) {
                QTableWidgetItem* item = m_table->item(i, j);
                if (item && item->text().contains(searchText, Qt::CaseInsensitive)) {
                    match = true;
                    break;
                }
            }
            visible = match;
        }

        m_table->setRowHidden(i, !visible);
    }
}

int ProductView::getSelectedVehicleId() {
    int row = m_table->currentRow();
    if (row < 0) return -1;

    return m_table->item(row, 0)->text().toInt();
}

void ProductView::onAddVehicle() {
    bool ok;
    QStringList types = {"Car", "Motorcycle"};
    QString type = QInputDialog::getItem(this, "Select Type", "Vehicle Type:",
                                         types, 0, false, &ok);
    if (!ok) return;

    QString brand = QInputDialog::getText(this, "Add Vehicle", "Brand:",
                                          QLineEdit::Normal, "", &ok);
    if (!ok || brand.isEmpty()) return;

    QString model = QInputDialog::getText(this, "Add Vehicle", "Model:",
                                          QLineEdit::Normal, "", &ok);
    if (!ok || model.isEmpty()) return;

    QString extra = QInputDialog::getText(this, "Add Vehicle",
                                          type == "Car" ? "Type (Manual/Matic):" : "Category:",
                                          QLineEdit::Normal, "", &ok);
    if (!ok || extra.isEmpty()) return;

    double rate = QInputDialog::getDouble(this, "Add Vehicle", "Daily Rate:",
                                          0, 0, 10000000, 2, &ok);
    if (!ok) return;

    int id = IdGenerator::getInstance().getNextId("vehicle");

    std::unique_ptr<Vehicle> vehicle;
    if (type == "Car") {
        vehicle = m_vehicleController->createCar(id, brand.toStdString(), model.toStdString(),
                                                 extra.toStdString(), rate, true);
    } else {
        vehicle = m_vehicleController->createMotorcycle(id, brand.toStdString(), model.toStdString(),
                                                        extra.toStdString(), rate, true);
    }

    if (m_vehicleController->add(std::move(vehicle))) {
        loadVehiclesTable();
        emit dataChanged();
        QMessageBox::information(this, "Success", "Vehicle added successfully!");
    } else {
        QMessageBox::warning(this, "Error", "Failed to add vehicle.");
    }
}

void ProductView::onEditVehicle() {
    int vehicleId = getSelectedVehicleId();
    if (vehicleId < 0) {
        QMessageBox::warning(this, "Warning", "Please select a vehicle to edit.");
        return;
    }

    Vehicle* vehicle = m_vehicleController->getById(vehicleId);
    if (!vehicle) return;

    bool ok;
    double newRate = QInputDialog::getDouble(this, "Edit Vehicle", "New Daily Rate:",
                                             vehicle->getDailyRate(), 0, 10000000, 2, &ok);
    if (ok) {
        vehicle->setDailyRate(newRate);
        m_vehicleController->update(*vehicle);
        loadVehiclesTable();
        emit dataChanged();
        QMessageBox::information(this, "Success", "Vehicle updated successfully!");
    }
}

void ProductView::onDeleteVehicle() {
    int vehicleId = getSelectedVehicleId();
    if (vehicleId < 0) {
        QMessageBox::warning(this, "Warning", "Please select a vehicle to delete.");
        return;
    }

    if (QMessageBox::question(this, "Confirm", "Are you sure?") == QMessageBox::Yes) {
        if (m_vehicleController->remove(vehicleId)) {
            loadVehiclesTable();
            emit dataChanged();
            QMessageBox::information(this, "Success", "Vehicle deleted successfully!");
        }
    }
}

void ProductView::onSearchVehicle(const QString& text) {
    applyFilters();
}

void ProductView::onFilterType(int index) {
    applyFilters();
}

void ProductView::onFilterAvailability(int index) {
    applyFilters();
}
