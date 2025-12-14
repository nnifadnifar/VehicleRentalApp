#ifndef TRANSACTIONVIEW_H
#define TRANSACTIONVIEW_H

#include <QWidget>
#include <QTableWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "../controllers/usercontroller.h"
#include "../controllers/vehiclecontroller.h"
#include "../controllers/rentalcontroller.h"
#include "../models/transaction.h"

class TransactionView : public QWidget
{
    Q_OBJECT

public:
    explicit TransactionView(QWidget* parent,
                             UserController* userController,
                             VehicleController* vehicleController,
                             RentalController* rentalController);
    ~TransactionView() = default;

    // Setup New Rental Tab
    void setupNewRentalUi(QComboBox* comboCustomer,
                          QLabel* labelPhone,
                          QPushButton* btnQuickAdd,
                          QTableWidget* tableAvailable,
                          QTableWidget* tableCart,
                          QLabel* labelTotal,
                          QPushButton* btnClear,
                          QPushButton* btnProcess);

    // Setup Rentals Tab
    void setupRentalsUi(QTableWidget* tableRentals,
                        QLineEdit* searchEdit,
                        QPushButton* btnViewDetails,
                        QPushButton* btnDelete);

    void loadData();
    void refresh();
    void refreshAvailableVehicles();

signals:
    void dataChanged();

private slots:
    // New Rental
    void onCustomerSelected(int index);
    void onQuickAddCustomer();
    void onAddToCart();
    void onRemoveFromCart();
    void onClearCart();
    void onProcessRental();
    void onCartQuantityChanged(int value);
    void updateRentalTotal();

    // Rentals List
    void onSearchRentals(const QString& text);
    void onViewRentalDetails();
    void onDeleteRental();

private:
    UserController* m_userController;
    VehicleController* m_vehicleController;
    RentalController* m_rentalController;

    // New Rental UI
    QComboBox* m_comboCustomer;
    QLabel* m_labelPhone;
    QPushButton* m_btnQuickAdd;
    QTableWidget* m_tableAvailable;
    QTableWidget* m_tableCart;
    QLabel* m_labelTotal;
    QPushButton* m_btnClear;
    QPushButton* m_btnProcess;

    // Rentals List UI
    QTableWidget* m_tableRentals;
    QLineEdit* m_searchEdit;
    QPushButton* m_btnViewDetails;
    QPushButton* m_btnDelete;

    // Current transaction
    Transaction m_currentTransaction;

    // Helper methods
    void loadCustomerCombo();
    void loadAvailableVehicles();
    void loadRentalsTable();
    void applyFilters();
    int getSelectedRentalId();
};

#endif // TRANSACTIONVIEW_H
