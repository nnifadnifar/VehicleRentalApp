#include "userview.h"
#include <QMessageBox>
#include <QInputDialog>

UserView::UserView(QWidget* parent,
                           UserController* userController,
                           RentalController* rentalController)
    : QWidget(parent)
    , m_userController(userController)
    , m_rentalController(rentalController)
    , m_table(nullptr)
    , m_searchEdit(nullptr)
{
}

void UserView::setupUi(QTableWidget* table,
                           QLineEdit* searchEdit,
                           QPushButton* btnAdd,
                           QPushButton* btnEdit,
                           QPushButton* btnDelete,
                           QPushButton* btnViewHistory)
{
    m_table = table;
    m_searchEdit = searchEdit;
    m_btnAdd = btnAdd;
    m_btnEdit = btnEdit;
    m_btnDelete = btnDelete;
    m_btnViewHistory = btnViewHistory;

    // Connect signals
    connect(m_btnAdd, &QPushButton::clicked, this, &UserView::onAddCustomer);
    connect(m_btnEdit, &QPushButton::clicked, this, &UserView::onEditCustomer);
    connect(m_btnDelete, &QPushButton::clicked, this, &UserView::onDeleteCustomer);
    connect(m_searchEdit, &QLineEdit::textChanged, this, &UserView::onSearchCustomer);
    connect(m_btnViewHistory, &QPushButton::clicked, this, &UserView::onViewCustomerHistory);
}

void UserView::loadData() {
    loadCustomersTable();
}

void UserView::refresh() {
    loadCustomersTable();
}

void UserView::loadCustomersTable() {
    if (!m_table) return;

    m_table->setRowCount(0);
    auto customers = m_userController->getAll();

    for (size_t i = 0; i < customers.size(); ++i) {
        const auto& customer = customers[i];
        m_table->insertRow(i);

        // Calculate stats
        auto rentals = m_rentalController->getByCustomerId(customer.getId());
        double totalSpent = m_rentalController->getRevenueByCustomer(customer.getId());

        m_table->setItem(i, 0, new QTableWidgetItem(QString::number(customer.getId())));
        m_table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(customer.getName())));
        m_table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(customer.getPhone())));
        m_table->setItem(i, 3, new QTableWidgetItem(QString::number(rentals.size())));
        m_table->setItem(i, 4, new QTableWidgetItem(
                                   QString("Rp %L1").arg(totalSpent, 0, 'f', 0)
                                   ));
    }
}

int UserView::getSelectedCustomerId() {
    int row = m_table->currentRow();
    if (row < 0) return -1;

    return m_table->item(row, 0)->text().toInt();
}

void UserView::onAddCustomer() {
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
        loadCustomersTable();
        emit dataChanged();
        QMessageBox::information(this, "Success", "Customer added successfully!");
    } else {
        QMessageBox::warning(this, "Error", "Failed to add customer.");
    }
}

void UserView::onEditCustomer() {
    int customerId = getSelectedCustomerId();
    if (customerId < 0) {
        QMessageBox::warning(this, "Warning", "Please select a customer to edit.");
        return;
    }

    Customer* customer = m_userController->getById(customerId);
    if (!customer) return;

    bool ok;
    QString newName = QInputDialog::getText(this, "Edit Customer", "Name:",
                                            QLineEdit::Normal,
                                            QString::fromStdString(customer->getName()), &ok);
    if (!ok) return;

    QString newPhone = QInputDialog::getText(this, "Edit Customer", "Phone:",
                                             QLineEdit::Normal,
                                             QString::fromStdString(customer->getPhone()), &ok);
    if (!ok) return;

    customer->setName(newName.toStdString());
    customer->setPhone(newPhone.toStdString());

    if (m_userController->update(*customer)) {
        loadCustomersTable();
        emit dataChanged();
        QMessageBox::information(this, "Success", "Customer updated successfully!");
    }
}

void UserView::onDeleteCustomer() {
    int customerId = getSelectedCustomerId();
    if (customerId < 0) {
        QMessageBox::warning(this, "Warning", "Please select a customer to delete.");
        return;
    }

    // Check if customer has rentals
    auto rentals = m_rentalController->getByCustomerId(customerId);
    if (!rentals.empty()) {
        QMessageBox::warning(this, "Warning", "Cannot delete customer with rental history.");
        return;
    }

    if (QMessageBox::question(this, "Confirm", "Are you sure?") == QMessageBox::Yes) {
        if (m_userController->remove(customerId)) {
            loadCustomersTable();
            emit dataChanged();
            QMessageBox::information(this, "Success", "Customer deleted successfully!");
        }
    }
}

void UserView::onSearchCustomer(const QString& text) {
    for (int i = 0; i < m_table->rowCount(); ++i) {
        bool match = false;
        for (int j = 0; j < m_table->columnCount(); ++j) {
            QTableWidgetItem* item = m_table->item(i, j);
            if (item && item->text().contains(text, Qt::CaseInsensitive)) {
                match = true;
                break;
            }
        }
        m_table->setRowHidden(i, !match);
    }
}

void UserView::onViewCustomerHistory() {
    int customerId = getSelectedCustomerId();
    if (customerId < 0) {
        QMessageBox::warning(this, "Warning", "Please select a customer.");
        return;
    }

    Customer* customer = m_userController->getById(customerId);
    if (!customer) return;

    auto rentals = m_rentalController->getByCustomerId(customerId);

    QString history = QString("Rental History for %1\n\n").arg(QString::fromStdString(customer->getName()));
    for (const auto* rental : rentals) {
        history += QString("ID: %1 | Date: %2 | Total: %3\n")
        .arg(rental->getId())
            .arg(QString::fromStdString(rental->getDateTime()))
            .arg(rental->getSubtotal(), 0, 'f', 0);
    }

    QMessageBox::information(this, "Customer History", history);
}
