#include "TransactionView.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QSpinBox>
#include <QPushButton>

TransactionView::TransactionView(QWidget* parent,
                                 UserController* userController,
                                 VehicleController* vehicleController,
                                 RentalController* rentalController)
    : QWidget(parent)
    , m_userController(userController)
    , m_vehicleController(vehicleController)
    , m_rentalController(rentalController)
{
}

void TransactionView::setupNewRentalUi(QComboBox* comboCustomer,
                                       QLabel* labelPhone,
                                       QPushButton* btnQuickAdd,
                                       QTableWidget* tableAvailable,
                                       QTableWidget* tableCart,
                                       QLabel* labelTotal,
                                       QPushButton* btnClear,
                                       QPushButton* btnProcess)
{
    m_comboCustomer = comboCustomer;
    m_labelPhone = labelPhone;
    m_btnQuickAdd = btnQuickAdd;
    m_tableAvailable = tableAvailable;
    m_tableCart = tableCart;
    m_labelTotal = labelTotal;
    m_btnClear = btnClear;
    m_btnProcess = btnProcess;

    // Connect signals
    connect(m_comboCustomer, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &TransactionView::onCustomerSelected);
    connect(m_btnQuickAdd, &QPushButton::clicked, this, &TransactionView::onQuickAddCustomer);
    connect(m_btnClear, &QPushButton::clicked, this, &TransactionView::onClearCart);
    connect(m_btnProcess, &QPushButton::clicked, this, &TransactionView::onProcessRental);
}

void TransactionView::setupRentalsUi(QTableWidget* tableRentals,
                                     QLineEdit* searchEdit,
                                     QPushButton* btnViewDetails,
                                     QPushButton* btnDelete,
                                     QPushButton* btnReturn)  // TAMBAHAN parameter
{
    m_tableRentals = tableRentals;
    m_searchEdit = searchEdit;
    m_btnViewDetails = btnViewDetails;
    m_btnDelete = btnDelete;
    m_btnReturn = btnReturn;  // TAMBAHAN

    // Connect signals
    connect(m_searchEdit, &QLineEdit::textChanged, this, &TransactionView::onSearchRentals);
    connect(m_btnViewDetails, &QPushButton::clicked, this, &TransactionView::onViewRentalDetails);
    connect(m_btnDelete, &QPushButton::clicked, this, &TransactionView::onDeleteRental);
    connect(m_btnReturn, &QPushButton::clicked, this, &TransactionView::onReturnVehicle);  // TAMBAHAN
}

void TransactionView::loadData() {
    loadCustomerCombo();
    loadAvailableVehicles();
    loadRentalsTable();
}

void TransactionView::refresh() {
    loadRentalsTable();
}

void TransactionView::refreshAvailableVehicles() {
    loadAvailableVehicles();
}

void TransactionView::loadCustomerCombo() {
    if (!m_comboCustomer) return;

    m_comboCustomer->clear();
    auto customers = m_userController->getAll();

    for (const auto& customer : customers) {
        m_comboCustomer->addItem(
            QString("%1 - %2")
                .arg(QString::fromStdString(customer.getName()))
                .arg(QString::fromStdString(customer.getPhone())),
            customer.getId()
            );
    }

    if (m_comboCustomer->count() > 0) {
        m_comboCustomer->setCurrentIndex(0);
    }
}

void TransactionView::loadAvailableVehicles() {
    if (!m_tableAvailable) return;

    // Disconnect previous connections
    for (int i = 0; i < m_tableAvailable->rowCount(); ++i) {
        QWidget* widget = m_tableAvailable->cellWidget(i, 6);
        if (widget) {
            widget->disconnect();
        }
    }

    m_tableAvailable->setRowCount(0);
    auto vehicles = m_vehicleController->getAll();

    int row = 0;
    for (const auto* vehicle : vehicles) {
        if (!vehicle->isAvailable()) continue;

        m_tableAvailable->insertRow(row);
        m_tableAvailable->setItem(row, 0, new QTableWidgetItem(QString::number(vehicle->getId())));
        m_tableAvailable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(vehicle->getVehicleType())));
        m_tableAvailable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(vehicle->getBrand())));
        m_tableAvailable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(vehicle->getModel())));
        m_tableAvailable->setItem(row, 4, new QTableWidgetItem(
                                              QString("Rp %L1").arg(vehicle->getDailyRate(), 0, 'f', 0)
                                              ));

        // Spinbox for days
        QSpinBox* spinBox = new QSpinBox();
        spinBox->setMinimum(1);
        spinBox->setMaximum(365);
        spinBox->setValue(1);
        m_tableAvailable->setCellWidget(row, 5, spinBox);

        // Add button
        QPushButton* btnAdd = new QPushButton("Add");
        btnAdd->setProperty("vehicleId", vehicle->getId());
        btnAdd->setProperty("row", row);
        connect(btnAdd, &QPushButton::clicked, this, &TransactionView::onAddToCart);
        m_tableAvailable->setCellWidget(row, 6, btnAdd);

        row++;
    }
}

void TransactionView::loadRentalsTable() {
    if (!m_tableRentals) return;

    m_tableRentals->setRowCount(0);
    auto rentals = m_rentalController->getAll();

    for (size_t i = 0; i < rentals.size(); ++i) {
        const auto& rental = rentals[i];
        m_tableRentals->insertRow(i);

        Customer* customer = m_userController->getById(rental.getCustomerId());
        QString customerName = customer ? QString::fromStdString(customer->getName()) : "Unknown";

        // TAMBAHAN: Cek apakah ada kendaraan yang masih di-rent
        bool hasActiveVehicles = rental.hasDays();
        QString status = hasActiveVehicles ? "Active" : "Completed";

        m_tableRentals->setItem(i, 0, new QTableWidgetItem(QString::number(rental.getId())));
        m_tableRentals->setItem(i, 1, new QTableWidgetItem(customerName));
        m_tableRentals->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(rental.getDateTime())));
        m_tableRentals->setItem(i, 3, new QTableWidgetItem(QString::number(rental.getDays().size())));
        m_tableRentals->setItem(i, 4, new QTableWidgetItem(QString::number(rental.getTotalDays())));
        m_tableRentals->setItem(i, 5, new QTableWidgetItem(
                                          QString("Rp %L1").arg(rental.getSubtotal(), 0, 'f', 0)
                                          ));

        // TAMBAHAN: Status column
        QTableWidgetItem* statusItem = new QTableWidgetItem(status);
        if (hasActiveVehicles) {
            statusItem->setBackground(QBrush(QColor(255, 193, 7, 100))); // Orange
        } else {
            statusItem->setBackground(QBrush(QColor(76, 175, 80, 100))); // Green
        }
        m_tableRentals->setItem(i, 6, statusItem);
    }

    applyFilters();
}

void TransactionView::applyFilters() {
    if (!m_tableRentals || !m_searchEdit) return;

    QString searchText = m_searchEdit->text();

    for (int i = 0; i < m_tableRentals->rowCount(); ++i) {
        bool match = false;

        if (searchText.isEmpty()) {
            match = true;
        } else {
            for (int j = 0; j < m_tableRentals->columnCount(); ++j) {
                QTableWidgetItem* item = m_tableRentals->item(i, j);
                if (item && item->text().contains(searchText, Qt::CaseInsensitive)) {
                    match = true;
                    break;
                }
            }
        }

        m_tableRentals->setRowHidden(i, !match);
    }
}

void TransactionView::onCustomerSelected(int index) {
    if (index < 0 || !m_comboCustomer) return;

    int customerId = m_comboCustomer->currentData().toInt();
    Customer* customer = m_userController->getById(customerId);

    if (customer && m_labelPhone) {
        m_labelPhone->setText(QString::fromStdString(customer->getPhone()));
        m_currentTransaction = m_rentalController->createTransaction(customerId);
    }
}

void TransactionView::onQuickAddCustomer() {
    bool ok;
    QString name = QInputDialog::getText(this, "Add Customer", "Name:",
                                         QLineEdit::Normal, "", &ok);
    if (!ok || name.isEmpty()) return;

    QString phone = QInputDialog::getText(this, "Add Customer", "Phone:",
                                          QLineEdit::Normal, "", &ok);
    if (!ok || phone.isEmpty()) return;

    Customer customer = m_userController->createCustomer(name.toStdString(),
                                                         phone.toStdString());

    if (m_userController->add(customer)) {
        loadCustomerCombo();
        m_comboCustomer->setCurrentIndex(m_comboCustomer->count() - 1);
        emit dataChanged();
        QMessageBox::information(this, "Success", "Customer added!");
    }
}

void TransactionView::onAddToCart() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    int vehicleId = button->property("vehicleId").toInt();
    int row = button->property("row").toInt();

    Vehicle* vehicle = m_vehicleController->getById(vehicleId);
    if (!vehicle) return;

    // Check if already in cart
    if (m_currentTransaction.getDay(vehicleId)) {
        QMessageBox::warning(this, "Warning", "Vehicle already in cart.");
        return;
    }

    QSpinBox* spinBox = qobject_cast<QSpinBox*>(m_tableAvailable->cellWidget(row, 5));
    int days = spinBox ? spinBox->value() : 1;

    // Create transaction day
    TransactionDays day(vehicleId, vehicle->getDescription(),
                        vehicle->getDailyRate(), days, "", "");
    m_currentTransaction.addDay(day);

    // Update cart table
    int cartRow = m_tableCart->rowCount();
    m_tableCart->insertRow(cartRow);
    m_tableCart->setItem(cartRow, 0, new QTableWidgetItem(QString::fromStdString(vehicle->getDescription())));
    m_tableCart->setItem(cartRow, 1, new QTableWidgetItem(
                                         QString("Rp %L1").arg(vehicle->getDailyRate(), 0, 'f', 0)
                                         ));

    QSpinBox* cartSpinBox = new QSpinBox();
    cartSpinBox->setMinimum(1);
    cartSpinBox->setMaximum(365);
    cartSpinBox->setValue(days);
    cartSpinBox->setProperty("vehicleId", vehicleId);
    cartSpinBox->setProperty("row", cartRow);
    connect(cartSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &TransactionView::onCartQuantityChanged);
    m_tableCart->setCellWidget(cartRow, 2, cartSpinBox);

    m_tableCart->setItem(cartRow, 3, new QTableWidgetItem(
                                         QString("Rp %L1").arg(day.getSubtotal(), 0, 'f', 0)
                                         ));

    QPushButton* btnRemove = new QPushButton("Remove");
    btnRemove->setProperty("vehicleId", vehicleId);
    btnRemove->setProperty("row", cartRow);
    connect(btnRemove, &QPushButton::clicked, this, &TransactionView::onRemoveFromCart);
    m_tableCart->setCellWidget(cartRow, 4, btnRemove);

    updateRentalTotal();
}

void TransactionView::onRemoveFromCart() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    int vehicleId = button->property("vehicleId").toInt();
    int row = button->property("row").toInt();

    m_currentTransaction.removeDay(vehicleId);
    m_tableCart->removeRow(row);

    // Update row properties
    for (int i = row; i < m_tableCart->rowCount(); ++i) {
        QWidget* spinWidget = m_tableCart->cellWidget(i, 2);
        QWidget* btnWidget = m_tableCart->cellWidget(i, 4);

        if (spinWidget) spinWidget->setProperty("row", i);
        if (btnWidget) btnWidget->setProperty("row", i);
    }

    updateRentalTotal();
}

void TransactionView::onClearCart() {
    if (!m_currentTransaction.hasDays()) return;

    if (QMessageBox::question(this, "Clear", "Clear cart?") == QMessageBox::Yes) {
        m_currentTransaction.clearDays();
        m_tableCart->setRowCount(0);
        updateRentalTotal();
    }
}

void TransactionView::onCartQuantityChanged(int value) {
    QSpinBox* spinBox = qobject_cast<QSpinBox*>(sender());
    if (!spinBox) return;

    int vehicleId = spinBox->property("vehicleId").toInt();
    int row = spinBox->property("row").toInt();

    m_currentTransaction.updateDaysDuration(vehicleId, value);

    TransactionDays* day = m_currentTransaction.getDay(vehicleId);
    if (day && row < m_tableCart->rowCount()) {
        m_tableCart->item(row, 3)->setText(
            QString("Rp %L1").arg(day->getSubtotal(), 0, 'f', 0)
            );
    }

    updateRentalTotal();
}

void TransactionView::updateRentalTotal() {
    m_currentTransaction.recalculate();
    if (m_labelTotal) {
        m_labelTotal->setText(
            QString("Rp %L1").arg(m_currentTransaction.getSubtotal(), 0, 'f', 0)
            );
    }
}

void TransactionView::onProcessRental() {
    if (!m_currentTransaction.hasDays()) {
        QMessageBox::warning(this, "Warning", "Cart is empty.");
        return;
    }

    if (!m_comboCustomer || m_comboCustomer->currentIndex() < 0) {
        QMessageBox::warning(this, "Warning", "Select a customer.");
        return;
    }

    if (QMessageBox::question(this, "Confirm", "Process rental?") == QMessageBox::Yes) {
        m_currentTransaction.setCurrentDateTime();

        if (m_rentalController->add(m_currentTransaction)) {
            // Mark vehicles as unavailable
            for (const auto& day : m_currentTransaction.getDays()) {
                Vehicle* vehicle = m_vehicleController->getById(day.getVehicleId());
                if (vehicle) {
                    vehicle->setAvailable(false);
                    m_vehicleController->update(*vehicle);
                }
            }

            QMessageBox::information(this, "Success", "Rental completed!");

            // Reset
            onClearCart();
            loadAvailableVehicles();
            loadRentalsTable();
            emit dataChanged();

            int customerId = m_comboCustomer->currentData().toInt();
            m_currentTransaction = m_rentalController->createTransaction(customerId);
        }
    }
}

void TransactionView::onSearchRentals(const QString& text) {
    applyFilters();
}

int TransactionView::getSelectedRentalId() {
    if (!m_tableRentals) return -1;

    int row = m_tableRentals->currentRow();
    if (row < 0) return -1;

    return m_tableRentals->item(row, 0)->text().toInt();
}

void TransactionView::onViewRentalDetails() {
    int rentalId = getSelectedRentalId();
    if (rentalId < 0) {
        QMessageBox::warning(this, "Warning", "Select a rental.");
        return;
    }

    Transaction* rental = m_rentalController->getById(rentalId);
    if (!rental) return;

    Customer* customer = m_userController->getById(rental->getCustomerId());

    QString details = QString("Rental #%1\n\n").arg(rental->getId());
    details += QString("Customer: %1\n").arg(customer ? QString::fromStdString(customer->getName()) : "Unknown");
    details += QString("Date: %1\n\n").arg(QString::fromStdString(rental->getDateTime()));
    details += "Vehicles:\n";

    for (const auto& day : rental->getDays()) {
        Vehicle* vehicle = m_vehicleController->getById(day.getVehicleId());
        QString vehicleStatus = vehicle ? (vehicle->isAvailable() ? " ✓ Returned" : " ⏳ Not Returned") : "";

        details += QString("- %1 x %2 days = Rp %3%4\n")
                       .arg(QString::fromStdString(day.getVehicleName()))
                       .arg(day.getRentalDays())
                       .arg(day.getSubtotal(), 0, 'f', 0)
                       .arg(vehicleStatus);
    }

    details += QString("\nTotal: Rp %L1").arg(rental->getSubtotal(), 0, 'f', 0);

    QMessageBox::information(this, "Rental Details", details);
}

void TransactionView::onDeleteRental() {
    int rentalId = getSelectedRentalId();
    if (rentalId < 0) {
        QMessageBox::warning(this, "Warning", "Select a rental.");
        return;
    }

    if (QMessageBox::question(this, "Confirm", "Delete rental?") == QMessageBox::Yes) {
        Transaction* rental = m_rentalController->getById(rentalId);
        if (rental) {
            // Mark vehicles as available
            for (const auto& day : rental->getDays()) {
                Vehicle* vehicle = m_vehicleController->getById(day.getVehicleId());
                if (vehicle) {
                    vehicle->setAvailable(true);
                    m_vehicleController->update(*vehicle);
                }
            }
        }

        if (m_rentalController->remove(rentalId)) {
            loadRentalsTable();
            loadAvailableVehicles();
            emit dataChanged();
            QMessageBox::information(this, "Success", "Rental deleted!");
        }
    }
}

// ============ FITUR BARU: RETURN VEHICLE ============
void TransactionView::onReturnVehicle() {
    int rentalId = getSelectedRentalId();
    if (rentalId < 0) {
        QMessageBox::warning(this, "Warning", "Please select a rental.");
        return;
    }

    Transaction* rental = m_rentalController->getById(rentalId);
    if (!rental) return;

    // Check if ada kendaraan yang belum dikembalikan
    QStringList unreturned;
    for (const auto& day : rental->getDays()) {
        Vehicle* vehicle = m_vehicleController->getById(day.getVehicleId());
        if (vehicle && !vehicle->isAvailable()) {
            unreturned << QString("%1 - %2 %3")
            .arg(day.getVehicleId())
                .arg(QString::fromStdString(vehicle->getBrand()))
                .arg(QString::fromStdString(vehicle->getModel()));
        }
    }

    if (unreturned.isEmpty()) {
        QMessageBox::information(this, "Info", "All vehicles have been returned.");
        return;
    }

    // Pilih kendaraan yang mau dikembalikan
    bool ok;
    QString selected = QInputDialog::getItem(this, "Return Vehicle",
                                             "Select vehicle to return:",
                                             unreturned, 0, false, &ok);
    if (!ok) return;

    // Extract vehicle ID
    int vehicleId = selected.split(" - ").first().toInt();

    Vehicle* vehicle = m_vehicleController->getById(vehicleId);
    if (!vehicle) return;

    // Konfirmasi
    QString confirmMsg = QString("Return this vehicle?\n\n%1 %2")
                             .arg(QString::fromStdString(vehicle->getBrand()))
                             .arg(QString::fromStdString(vehicle->getModel()));

    if (QMessageBox::question(this, "Confirm Return", confirmMsg) == QMessageBox::Yes) {
        // Mark vehicle as available
        vehicle->setAvailable(true);
        m_vehicleController->update(*vehicle);

        QMessageBox::information(this, "Success",
                                 QString("Vehicle %1 %2 has been returned!")
                                     .arg(QString::fromStdString(vehicle->getBrand()))
                                     .arg(QString::fromStdString(vehicle->getModel())));

        // Refresh tables
        loadRentalsTable();
        loadAvailableVehicles();
        emit dataChanged();
    }
}
