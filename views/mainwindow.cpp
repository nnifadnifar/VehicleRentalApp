#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userview.h"
#include "ProductView.h"
#include "transactionview.h"
#include <QMessageBox>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_dataHandler("data/")
    , m_userController(m_dataHandler)
    , m_vehicleController(m_dataHandler)
    , m_rentalController(m_dataHandler)
    , m_UserView(nullptr)
    , m_productView(nullptr)
    , m_transactionView(nullptr)
{
    ui->setupUi(this);

    // PENTING: Pastikan folder data/ ada
    m_dataHandler.ensureFileExists("customer.txt");
    m_dataHandler.ensureFileExists("vehicle.txt");
    m_dataHandler.ensureFileExists("rental.txt");

    loadAllData();
    setupViews();
    setupConnections();
    setupDashboard();
    updateDashboard();
}

MainWindow::~MainWindow()
{
    // AUTO SAVE saat aplikasi ditutup
    saveAllData();

    delete m_UserView;
    delete m_productView;
    delete m_transactionView;
    delete ui;
}

// TAMBAHKAN: Override closeEvent untuk auto-save
void MainWindow::closeEvent(QCloseEvent *event)
{
    saveAllData();
    QMessageBox::information(this, "Data Saved", "All data has been saved automatically.");
    event->accept();
}

void MainWindow::setupViews()
{
    // Initialize Customer View
    m_UserView = new UserView(this, &m_userController, &m_rentalController);
    m_UserView->setupUi(
        ui->tableCustomers,
        ui->lineEditSearchCustomer,
        ui->btnAddCustomer,
        ui->btnEditCustomer,
        ui->btnDeleteCustomer,
        ui->btnViewCustomerHistory
        );

    // Initialize Product View
    m_productView = new ProductView(this, &m_vehicleController);
    m_productView->setupUi(
        ui->tableVehicles,
        ui->lineEditSearchVehicle,
        ui->comboBoxFilterType,
        ui->comboBoxFilterAvailability,
        ui->btnAddVehicle,
        ui->btnEditVehicle,
        ui->btnDeleteVehicle
        );

    // Initialize Transaction View
    m_transactionView = new TransactionView(this, &m_userController,
                                            &m_vehicleController,
                                            &m_rentalController);

    // Setup New Rental Tab
    m_transactionView->setupNewRentalUi(
        ui->comboBoxSelectCustomer,
        ui->labelCustomerPhone,
        ui->btnQuickAddCustomer,
        ui->tableAvailableVehicles,
        ui->tableRentalCart,
        ui->labelRentalTotal,
        ui->btnClearCart,
        ui->btnProcessRental
        );

    // Setup Rentals Tab (dengan fitur return)
    m_transactionView->setupRentalsUi(
        ui->tableRentals,
        ui->lineEditSearchRental,
        ui->btnViewRentalDetails,
        ui->btnDeleteRental,
        ui->btnReturnVehicle  // TAMBAHAN: tombol return
        );

    // Load initial data
    m_UserView->loadData();
    m_productView->loadData();
    m_transactionView->loadData();
}

void MainWindow::setupConnections()
{
    // Tab changed
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);

    // Data changed signals - TAMBAHKAN AUTO SAVE
    connect(m_UserView, &UserView::dataChanged, this, [this]() {
        updateDashboard();
        saveAllData(); // Auto save
    });

    connect(m_productView, &ProductView::dataChanged, this, [this]() {
        updateDashboard();
        saveAllData(); // Auto save
    });

    connect(m_transactionView, &TransactionView::dataChanged, this, [this]() {
        updateDashboard();
        m_productView->refresh();
        m_transactionView->refreshAvailableVehicles();
        saveAllData(); // Auto save
    });

    // Menu actions
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::onSaveAll);
    connect(ui->actionLoad, &QAction::triggered, this, &MainWindow::onLoadAll);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::onAbout);
}

void MainWindow::loadAllData()
{
    m_userController.loadFromFile();
    m_vehicleController.loadFromFile();
    m_rentalController.loadFromFile();
}

void MainWindow::saveAllData()
{
    m_userController.saveToFile();
    m_vehicleController.saveToFile();
    m_rentalController.saveToFile();
}

void MainWindow::setupDashboard()
{
    ui->tableRecentRentals->horizontalHeader()->setStretchLastSection(true);
    ui->tableRecentRentals->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableRecentRentals->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::updateDashboard()
{
    updateDashboardStats();
    loadRecentRentals();
}

void MainWindow::updateDashboardStats()
{
    // Total vehicles
    int totalVehicles = m_vehicleController.getCount();
    ui->labelTotalVehicles->setText(QString::number(totalVehicles));

    // Available vehicles
    int availableCount = 0;
    auto vehicles = m_vehicleController.getAll();
    for (const auto* vehicle : vehicles) {
        if (vehicle->isAvailable()) {
            availableCount++;
        }
    }
    ui->labelAvailableVehicles->setText(QString::number(availableCount));

    // Active rentals
    auto activeRentals = m_rentalController.getActiveRentals();
    ui->labelActiveRentals->setText(QString::number(activeRentals.size()));

    // Total revenue
    double totalRevenue = m_rentalController.getTotalRevenue();
    ui->labelTotalRevenue->setText(QString("Rp %L1").arg(totalRevenue, 0, 'f', 0));
}

void MainWindow::loadRecentRentals()
{
    ui->tableRecentRentals->setRowCount(0);
    auto rentals = m_rentalController.getAll();

    int startIndex = std::max(0, static_cast<int>(rentals.size()) - 10);

    for (int i = startIndex; i < static_cast<int>(rentals.size()); ++i) {
        const auto& rental = rentals[rentals.size() - 1 - (i - startIndex)];
        int row = i - startIndex;
        ui->tableRecentRentals->insertRow(row);

        Customer* customer = m_userController.getById(rental.getCustomerId());
        QString customerName = customer ? QString::fromStdString(customer->getName()) : "Unknown";

        ui->tableRecentRentals->setItem(row, 0, new QTableWidgetItem(QString::number(rental.getId())));
        ui->tableRecentRentals->setItem(row, 1, new QTableWidgetItem(customerName));
        ui->tableRecentRentals->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(rental.getDateTime())));
        ui->tableRecentRentals->setItem(row, 3, new QTableWidgetItem(QString::number(rental.getTotalDays())));
        ui->tableRecentRentals->setItem(row, 4, new QTableWidgetItem(
                                                    QString("Rp %L1").arg(rental.getSubtotal(), 0, 'f', 0)
                                                    ));
    }
}

void MainWindow::onTabChanged(int index)
{
    switch (index) {
    case 0: // Dashboard
        updateDashboard();
        break;
    case 1: // Vehicles
        m_productView->refresh();
        break;
    case 2: // Customers
        m_UserView->refresh();
        break;
    case 3: // New Rental
        m_transactionView->refreshAvailableVehicles();
        break;
    case 4: // Rentals
        m_transactionView->refresh();
        break;
    }
}

void MainWindow::onSaveAll()
{
    saveAllData();
    QMessageBox::information(this, "Success", "All data saved successfully!");
}

void MainWindow::onLoadAll()
{
    loadAllData();

    m_UserView->refresh();
    m_productView->refresh();
    m_transactionView->loadData();
    updateDashboard();

    QMessageBox::information(this, "Success", "All data loaded successfully!");
}

void MainWindow::onAbout()
{
    QMessageBox::about(this, "About",
                       "TransGo\n"
                       "Version 2.0\n\n"
                       "A system for managing vehicle rentals.");
}
