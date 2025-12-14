#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../controllers/usercontroller.h"
#include "../controllers/vehiclecontroller.h"
#include "../controllers/rentalcontroller.h"
#include "../utils/datahandler.h"
#include "userview.h"

// Forward declarations
class UserView;
class ProductView;
class TransactionView;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    // TAMBAHAN: Override untuk auto-save saat close
    void closeEvent(QCloseEvent *event) override;

private slots:
    void onTabChanged(int index);
    void updateDashboard();
    void onSaveAll();
    void onLoadAll();
    void onAbout();

private:
    Ui::MainWindow *ui;

    // Controllers
    DataHandler m_dataHandler;
    UserController m_userController;
    VehicleController m_vehicleController;
    RentalController m_rentalController;

    // Views
    UserView* m_UserView;
    ProductView* m_productView;
    TransactionView* m_transactionView;

    // Helper methods
    void setupViews();
    void setupConnections();
    void loadAllData();
    void saveAllData();
    void setupDashboard();
    void updateDashboardStats();
    void loadRecentRentals();
};

#endif // MAINWINDOW_H
