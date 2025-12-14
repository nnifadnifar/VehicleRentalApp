#ifndef USERVIEW_H
#define USERVIEW_H

#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include "../controllers/usercontroller.h"
#include "../controllers/rentalcontroller.h"

class UserView : public QWidget
{
    Q_OBJECT

public:
    explicit UserView(QWidget* parent,
                          UserController* userController,
                          RentalController* rentalController);
    ~UserView() = default;

    void setupUi(QTableWidget* table,
                 QLineEdit* searchEdit,
                 QPushButton* btnAdd,
                 QPushButton* btnEdit,
                 QPushButton* btnDelete,
                 QPushButton* btnViewHistory);

    void loadData();
    void refresh();

signals:
    void dataChanged();

private slots:
    void onAddCustomer();
    void onEditCustomer();
    void onDeleteCustomer();
    void onSearchCustomer(const QString& text);
    void onViewCustomerHistory();

private:
    UserController* m_userController;
    RentalController* m_rentalController;

    QTableWidget* m_table;
    QLineEdit* m_searchEdit;
    QPushButton* m_btnAdd;
    QPushButton* m_btnEdit;
    QPushButton* m_btnDelete;
    QPushButton* m_btnViewHistory;

    void loadCustomersTable();
    int getSelectedCustomerId();
};

#endif // CUSTOMERVIEW_H
