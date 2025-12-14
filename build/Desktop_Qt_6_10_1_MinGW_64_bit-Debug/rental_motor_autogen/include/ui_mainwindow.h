/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabDashboard;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QFrame *frameStats1;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelStatsTitle1;
    QLabel *labelTotalVehicles;
    QFrame *frameStats2;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelStatsTitle2;
    QLabel *labelAvailableVehicles;
    QFrame *frameStats3;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelStatsTitle3;
    QLabel *labelActiveRentals;
    QFrame *frameStats4;
    QVBoxLayout *verticalLayout_6;
    QLabel *labelStatsTitle4;
    QLabel *labelTotalRevenue;
    QLabel *labelRecentTitle;
    QTableWidget *tableRecentRentals;
    QWidget *tabVehicles;
    QVBoxLayout *verticalLayout_7;
    QFrame *frameVehicleFilter;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditSearchVehicle;
    QComboBox *comboBoxFilterType;
    QComboBox *comboBoxFilterAvailability;
    QPushButton *btnAddVehicle;
    QTableWidget *tableVehicles;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnEditVehicle;
    QPushButton *btnDeleteVehicle;
    QWidget *tabCustomers;
    QVBoxLayout *verticalLayout_8;
    QFrame *frameCustomerFilter;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEditSearchCustomer;
    QPushButton *btnAddCustomer;
    QTableWidget *tableCustomers;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnEditCustomer;
    QPushButton *btnDeleteCustomer;
    QPushButton *btnViewCustomerHistory;
    QWidget *tabNewRental;
    QHBoxLayout *horizontalLayoutMain;
    QFrame *frameLeft;
    QVBoxLayout *verticalLayout_10;
    QLabel *labelAvailableTitle;
    QTableWidget *tableAvailableVehicles;
    QVBoxLayout *verticalLayoutRight;
    QFrame *frameCustomer;
    QVBoxLayout *verticalLayout_9;
    QLabel *labelCustomerTitle;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *comboBoxSelectCustomer;
    QPushButton *btnQuickAddCustomer;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelPhoneTitle;
    QLabel *labelCustomerPhone;
    QFrame *frameCart;
    QVBoxLayout *verticalLayout_11;
    QLabel *labelCartTitle;
    QTableWidget *tableRentalCart;
    QFrame *frameTotalSection;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelTotalText;
    QSpacerItem *spacerItem;
    QLabel *labelRentalTotal;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *btnClearCart;
    QPushButton *btnProcessRental;
    QWidget *tabRentals;
    QVBoxLayout *verticalLayout_12;
    QFrame *frameRentalFilter;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *lineEditSearchRental;
    QPushButton *btnViewRentalDetails;
    QPushButton *btnDeleteRental;
    QTableWidget *tableRentals;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1400, 900);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow {\n"
"        background-color: #f5f5f5;\n"
"    }\n"
"    QTabWidget::pane {\n"
"        border: 1px solid #ddd;\n"
"        background: white;\n"
"    }\n"
"    QTabBar::tab {\n"
"        background: #e0e0e0;\n"
"        padding: 10px 20px;\n"
"        margin-right: 2px;\n"
"        border-top-left-radius: 4px;\n"
"        border-top-right-radius: 4px;\n"
"    }\n"
"    QTabBar::tab:selected {\n"
"        background: white;\n"
"        border-bottom: 2px solid #2196F3;\n"
"    }\n"
"    QPushButton {\n"
"        padding: 8px 16px;\n"
"        border-radius: 4px;\n"
"        border: none;\n"
"        font-weight: bold;\n"
"    }\n"
"    QPushButton#btnAddVehicle, QPushButton#btnAddCustomer {\n"
"        background-color: #4CAF50;\n"
"        color: white;\n"
"    }\n"
"    QPushButton#btnAddVehicle:hover, QPushButton#btnAddCustomer:hover {\n"
"        background-color: #45a049;\n"
"    }\n"
"    QPushButton#btnEditVehicle, QPushButton#btnEditCustomer {\n"
"        background-color: #2196F"
                        "3;\n"
"        color: white;\n"
"    }\n"
"    QPushButton#btnDeleteVehicle, QPushButton#btnDeleteCustomer, QPushButton#btnDeleteRental {\n"
"        background-color: #f44336;\n"
"        color: white;\n"
"    }\n"
"    QPushButton#btnProcessRental {\n"
"        background-color: #4CAF50;\n"
"        color: white;\n"
"        padding: 12px 24px;\n"
"        font-size: 14px;\n"
"    }\n"
"    QPushButton#btnClearCart {\n"
"        background-color: #f44336;\n"
"        color: white;\n"
"    }\n"
"    QLineEdit, QComboBox {\n"
"        padding: 6px;\n"
"        border: 1px solid #ddd;\n"
"        border-radius: 4px;\n"
"    }\n"
"    QTableWidget {\n"
"        border: 1px solid #ddd;\n"
"        gridline-color: #e0e0e0;\n"
"        selection-background-color: #e3f2fd;\n"
"    }\n"
"    QTableWidget::item {\n"
"        padding: 8px;\n"
"    }\n"
"    QHeaderView::section {\n"
"        background-color: #f5f5f5;\n"
"        padding: 8px;\n"
"        border: none;\n"
"        border-right: 1px solid #ddd;\n"
"    "
                        "    border-bottom: 2px solid #ddd;\n"
"        font-weight: bold;\n"
"    }\n"
"    QGroupBox {\n"
"        font-weight: bold;\n"
"        border: 2px solid #ddd;\n"
"        border-radius: 6px;\n"
"        margin-top: 12px;\n"
"        padding-top: 10px;\n"
"    }\n"
"    QGroupBox::title {\n"
"        subcontrol-origin: margin;\n"
"        left: 10px;\n"
"        padding: 0 5px;\n"
"    }\n"
"   "));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName("actionLoad");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabPosition(QTabWidget::North);
        tabDashboard = new QWidget();
        tabDashboard->setObjectName("tabDashboard");
        verticalLayout_2 = new QVBoxLayout(tabDashboard);
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setContentsMargins(20, 20, 20, 20);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName("horizontalLayout");
        frameStats1 = new QFrame(tabDashboard);
        frameStats1->setObjectName("frameStats1");
        frameStats1->setFrameShape(QFrame::StyledPanel);
        frameStats1->setFrameShadow(QFrame::Raised);
        frameStats1->setStyleSheet(QString::fromUtf8("\n"
"              QFrame {\n"
"                  background-color: white;\n"
"                  border-radius: 8px;\n"
"                  border: 1px solid #e0e0e0;\n"
"              }\n"
"             "));
        verticalLayout_3 = new QVBoxLayout(frameStats1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        labelStatsTitle1 = new QLabel(frameStats1);
        labelStatsTitle1->setObjectName("labelStatsTitle1");
        labelStatsTitle1->setStyleSheet(QString::fromUtf8("color: #666; font-size: 14px;"));

        verticalLayout_3->addWidget(labelStatsTitle1);

        labelTotalVehicles = new QLabel(frameStats1);
        labelTotalVehicles->setObjectName("labelTotalVehicles");
        labelTotalVehicles->setAlignment(Qt::AlignCenter);
        labelTotalVehicles->setStyleSheet(QString::fromUtf8("font-size: 42px; font-weight: bold; color: #2196F3;"));

        verticalLayout_3->addWidget(labelTotalVehicles);


        horizontalLayout->addWidget(frameStats1);

        frameStats2 = new QFrame(tabDashboard);
        frameStats2->setObjectName("frameStats2");
        frameStats2->setFrameShape(QFrame::StyledPanel);
        frameStats2->setStyleSheet(QString::fromUtf8("\n"
"              QFrame {\n"
"                  background-color: white;\n"
"                  border-radius: 8px;\n"
"                  border: 1px solid #e0e0e0;\n"
"              }\n"
"             "));
        verticalLayout_4 = new QVBoxLayout(frameStats2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        labelStatsTitle2 = new QLabel(frameStats2);
        labelStatsTitle2->setObjectName("labelStatsTitle2");
        labelStatsTitle2->setStyleSheet(QString::fromUtf8("color: #666; font-size: 14px;"));

        verticalLayout_4->addWidget(labelStatsTitle2);

        labelAvailableVehicles = new QLabel(frameStats2);
        labelAvailableVehicles->setObjectName("labelAvailableVehicles");
        labelAvailableVehicles->setAlignment(Qt::AlignCenter);
        labelAvailableVehicles->setStyleSheet(QString::fromUtf8("font-size: 42px; font-weight: bold; color: #4CAF50;"));

        verticalLayout_4->addWidget(labelAvailableVehicles);


        horizontalLayout->addWidget(frameStats2);

        frameStats3 = new QFrame(tabDashboard);
        frameStats3->setObjectName("frameStats3");
        frameStats3->setFrameShape(QFrame::StyledPanel);
        frameStats3->setStyleSheet(QString::fromUtf8("\n"
"              QFrame {\n"
"                  background-color: white;\n"
"                  border-radius: 8px;\n"
"                  border: 1px solid #e0e0e0;\n"
"              }\n"
"             "));
        verticalLayout_5 = new QVBoxLayout(frameStats3);
        verticalLayout_5->setObjectName("verticalLayout_5");
        labelStatsTitle3 = new QLabel(frameStats3);
        labelStatsTitle3->setObjectName("labelStatsTitle3");
        labelStatsTitle3->setStyleSheet(QString::fromUtf8("color: #666; font-size: 14px;"));

        verticalLayout_5->addWidget(labelStatsTitle3);

        labelActiveRentals = new QLabel(frameStats3);
        labelActiveRentals->setObjectName("labelActiveRentals");
        labelActiveRentals->setAlignment(Qt::AlignCenter);
        labelActiveRentals->setStyleSheet(QString::fromUtf8("font-size: 42px; font-weight: bold; color: #FF9800;"));

        verticalLayout_5->addWidget(labelActiveRentals);


        horizontalLayout->addWidget(frameStats3);

        frameStats4 = new QFrame(tabDashboard);
        frameStats4->setObjectName("frameStats4");
        frameStats4->setFrameShape(QFrame::StyledPanel);
        frameStats4->setStyleSheet(QString::fromUtf8("\n"
"              QFrame {\n"
"                  background-color: white;\n"
"                  border-radius: 8px;\n"
"                  border: 1px solid #e0e0e0;\n"
"              }\n"
"             "));
        verticalLayout_6 = new QVBoxLayout(frameStats4);
        verticalLayout_6->setObjectName("verticalLayout_6");
        labelStatsTitle4 = new QLabel(frameStats4);
        labelStatsTitle4->setObjectName("labelStatsTitle4");
        labelStatsTitle4->setStyleSheet(QString::fromUtf8("color: #666; font-size: 14px;"));

        verticalLayout_6->addWidget(labelStatsTitle4);

        labelTotalRevenue = new QLabel(frameStats4);
        labelTotalRevenue->setObjectName("labelTotalRevenue");
        labelTotalRevenue->setAlignment(Qt::AlignCenter);
        labelTotalRevenue->setStyleSheet(QString::fromUtf8("font-size: 32px; font-weight: bold; color: #9C27B0;"));

        verticalLayout_6->addWidget(labelTotalRevenue);


        horizontalLayout->addWidget(frameStats4);


        verticalLayout_2->addLayout(horizontalLayout);

        labelRecentTitle = new QLabel(tabDashboard);
        labelRecentTitle->setObjectName("labelRecentTitle");
        labelRecentTitle->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold; color: #333;"));

        verticalLayout_2->addWidget(labelRecentTitle);

        tableRecentRentals = new QTableWidget(tabDashboard);
        if (tableRecentRentals->columnCount() < 5)
            tableRecentRentals->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableRecentRentals->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableRecentRentals->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableRecentRentals->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableRecentRentals->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableRecentRentals->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableRecentRentals->setObjectName("tableRecentRentals");
        tableRecentRentals->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableRecentRentals->setAlternatingRowColors(true);
        tableRecentRentals->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableRecentRentals->setSortingEnabled(true);

        verticalLayout_2->addWidget(tableRecentRentals);

        tabWidget->addTab(tabDashboard, QString());
        tabVehicles = new QWidget();
        tabVehicles->setObjectName("tabVehicles");
        verticalLayout_7 = new QVBoxLayout(tabVehicles);
        verticalLayout_7->setSpacing(15);
        verticalLayout_7->setContentsMargins(20, 20, 20, 20);
        verticalLayout_7->setObjectName("verticalLayout_7");
        frameVehicleFilter = new QFrame(tabVehicles);
        frameVehicleFilter->setObjectName("frameVehicleFilter");
        frameVehicleFilter->setFrameShape(QFrame::StyledPanel);
        frameVehicleFilter->setStyleSheet(QString::fromUtf8("\n"
"            QFrame {\n"
"                background-color: white;\n"
"                border-radius: 8px;\n"
"                border: 1px solid #e0e0e0;\n"
"            }\n"
"           "));
        horizontalLayout_2 = new QHBoxLayout(frameVehicleFilter);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEditSearchVehicle = new QLineEdit(frameVehicleFilter);
        lineEditSearchVehicle->setObjectName("lineEditSearchVehicle");
        lineEditSearchVehicle->setMinimumHeight(36);

        horizontalLayout_2->addWidget(lineEditSearchVehicle);

        comboBoxFilterType = new QComboBox(frameVehicleFilter);
        comboBoxFilterType->addItem(QString());
        comboBoxFilterType->addItem(QString());
        comboBoxFilterType->addItem(QString());
        comboBoxFilterType->setObjectName("comboBoxFilterType");
        comboBoxFilterType->setMinimumHeight(36);

        horizontalLayout_2->addWidget(comboBoxFilterType);

        comboBoxFilterAvailability = new QComboBox(frameVehicleFilter);
        comboBoxFilterAvailability->addItem(QString());
        comboBoxFilterAvailability->addItem(QString());
        comboBoxFilterAvailability->addItem(QString());
        comboBoxFilterAvailability->setObjectName("comboBoxFilterAvailability");
        comboBoxFilterAvailability->setMinimumHeight(36);

        horizontalLayout_2->addWidget(comboBoxFilterAvailability);

        btnAddVehicle = new QPushButton(frameVehicleFilter);
        btnAddVehicle->setObjectName("btnAddVehicle");
        btnAddVehicle->setMinimumHeight(36);

        horizontalLayout_2->addWidget(btnAddVehicle);


        verticalLayout_7->addWidget(frameVehicleFilter);

        tableVehicles = new QTableWidget(tabVehicles);
        if (tableVehicles->columnCount() < 7)
            tableVehicles->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableVehicles->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableVehicles->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableVehicles->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableVehicles->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableVehicles->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableVehicles->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableVehicles->setHorizontalHeaderItem(6, __qtablewidgetitem11);
        tableVehicles->setObjectName("tableVehicles");
        tableVehicles->setAlternatingRowColors(true);
        tableVehicles->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableVehicles->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableVehicles->setSortingEnabled(true);

        verticalLayout_7->addWidget(tableVehicles);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btnEditVehicle = new QPushButton(tabVehicles);
        btnEditVehicle->setObjectName("btnEditVehicle");
        btnEditVehicle->setMinimumWidth(100);

        horizontalLayout_3->addWidget(btnEditVehicle);

        btnDeleteVehicle = new QPushButton(tabVehicles);
        btnDeleteVehicle->setObjectName("btnDeleteVehicle");
        btnDeleteVehicle->setMinimumWidth(100);

        horizontalLayout_3->addWidget(btnDeleteVehicle);


        verticalLayout_7->addLayout(horizontalLayout_3);

        tabWidget->addTab(tabVehicles, QString());
        tabCustomers = new QWidget();
        tabCustomers->setObjectName("tabCustomers");
        verticalLayout_8 = new QVBoxLayout(tabCustomers);
        verticalLayout_8->setSpacing(15);
        verticalLayout_8->setContentsMargins(20, 20, 20, 20);
        verticalLayout_8->setObjectName("verticalLayout_8");
        frameCustomerFilter = new QFrame(tabCustomers);
        frameCustomerFilter->setObjectName("frameCustomerFilter");
        frameCustomerFilter->setFrameShape(QFrame::StyledPanel);
        frameCustomerFilter->setStyleSheet(QString::fromUtf8("\n"
"            QFrame {\n"
"                background-color: white;\n"
"                border-radius: 8px;\n"
"                border: 1px solid #e0e0e0;\n"
"            }\n"
"           "));
        horizontalLayout_4 = new QHBoxLayout(frameCustomerFilter);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lineEditSearchCustomer = new QLineEdit(frameCustomerFilter);
        lineEditSearchCustomer->setObjectName("lineEditSearchCustomer");
        lineEditSearchCustomer->setMinimumHeight(36);

        horizontalLayout_4->addWidget(lineEditSearchCustomer);

        btnAddCustomer = new QPushButton(frameCustomerFilter);
        btnAddCustomer->setObjectName("btnAddCustomer");
        btnAddCustomer->setMinimumHeight(36);

        horizontalLayout_4->addWidget(btnAddCustomer);


        verticalLayout_8->addWidget(frameCustomerFilter);

        tableCustomers = new QTableWidget(tabCustomers);
        if (tableCustomers->columnCount() < 5)
            tableCustomers->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableCustomers->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableCustomers->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableCustomers->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableCustomers->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableCustomers->setHorizontalHeaderItem(4, __qtablewidgetitem16);
        tableCustomers->setObjectName("tableCustomers");
        tableCustomers->setAlternatingRowColors(true);
        tableCustomers->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableCustomers->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableCustomers->setSortingEnabled(true);

        verticalLayout_8->addWidget(tableCustomers);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        btnEditCustomer = new QPushButton(tabCustomers);
        btnEditCustomer->setObjectName("btnEditCustomer");
        btnEditCustomer->setMinimumWidth(100);

        horizontalLayout_5->addWidget(btnEditCustomer);

        btnDeleteCustomer = new QPushButton(tabCustomers);
        btnDeleteCustomer->setObjectName("btnDeleteCustomer");
        btnDeleteCustomer->setMinimumWidth(100);

        horizontalLayout_5->addWidget(btnDeleteCustomer);

        btnViewCustomerHistory = new QPushButton(tabCustomers);
        btnViewCustomerHistory->setObjectName("btnViewCustomerHistory");
        btnViewCustomerHistory->setStyleSheet(QString::fromUtf8("background-color: #FF9800; color: white;"));
        btnViewCustomerHistory->setMinimumWidth(120);

        horizontalLayout_5->addWidget(btnViewCustomerHistory);


        verticalLayout_8->addLayout(horizontalLayout_5);

        tabWidget->addTab(tabCustomers, QString());
        tabNewRental = new QWidget();
        tabNewRental->setObjectName("tabNewRental");
        horizontalLayoutMain = new QHBoxLayout(tabNewRental);
        horizontalLayoutMain->setSpacing(15);
        horizontalLayoutMain->setContentsMargins(20, 20, 20, 20);
        horizontalLayoutMain->setObjectName("horizontalLayoutMain");
        frameLeft = new QFrame(tabNewRental);
        frameLeft->setObjectName("frameLeft");
        frameLeft->setFrameShape(QFrame::StyledPanel);
        frameLeft->setStyleSheet(QString::fromUtf8("\n"
"            QFrame {\n"
"                background-color: white;\n"
"                border-radius: 8px;\n"
"                border: 1px solid #e0e0e0;\n"
"            }\n"
"           "));
        verticalLayout_10 = new QVBoxLayout(frameLeft);
        verticalLayout_10->setObjectName("verticalLayout_10");
        labelAvailableTitle = new QLabel(frameLeft);
        labelAvailableTitle->setObjectName("labelAvailableTitle");
        labelAvailableTitle->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold; color: #333;"));

        verticalLayout_10->addWidget(labelAvailableTitle);

        tableAvailableVehicles = new QTableWidget(frameLeft);
        if (tableAvailableVehicles->columnCount() < 7)
            tableAvailableVehicles->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableAvailableVehicles->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableAvailableVehicles->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableAvailableVehicles->setHorizontalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableAvailableVehicles->setHorizontalHeaderItem(3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableAvailableVehicles->setHorizontalHeaderItem(4, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableAvailableVehicles->setHorizontalHeaderItem(5, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableAvailableVehicles->setHorizontalHeaderItem(6, __qtablewidgetitem23);
        tableAvailableVehicles->setObjectName("tableAvailableVehicles");
        tableAvailableVehicles->setAlternatingRowColors(true);
        tableAvailableVehicles->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableAvailableVehicles->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_10->addWidget(tableAvailableVehicles);


        horizontalLayoutMain->addWidget(frameLeft);

        verticalLayoutRight = new QVBoxLayout();
        verticalLayoutRight->setSpacing(15);
        verticalLayoutRight->setObjectName("verticalLayoutRight");
        frameCustomer = new QFrame(tabNewRental);
        frameCustomer->setObjectName("frameCustomer");
        frameCustomer->setFrameShape(QFrame::StyledPanel);
        frameCustomer->setStyleSheet(QString::fromUtf8("\n"
"              QFrame {\n"
"                  background-color: white;\n"
"                  border-radius: 8px;\n"
"                  border: 1px solid #e0e0e0;\n"
"              }\n"
"             "));
        frameCustomer->setMinimumWidth(400);
        verticalLayout_9 = new QVBoxLayout(frameCustomer);
        verticalLayout_9->setObjectName("verticalLayout_9");
        labelCustomerTitle = new QLabel(frameCustomer);
        labelCustomerTitle->setObjectName("labelCustomerTitle");
        labelCustomerTitle->setStyleSheet(QString::fromUtf8("font-weight: bold; font-size: 14px;"));

        verticalLayout_9->addWidget(labelCustomerTitle);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        comboBoxSelectCustomer = new QComboBox(frameCustomer);
        comboBoxSelectCustomer->setObjectName("comboBoxSelectCustomer");
        comboBoxSelectCustomer->setMinimumHeight(36);

        horizontalLayout_6->addWidget(comboBoxSelectCustomer);

        btnQuickAddCustomer = new QPushButton(frameCustomer);
        btnQuickAddCustomer->setObjectName("btnQuickAddCustomer");
        btnQuickAddCustomer->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; color: white;"));

        horizontalLayout_6->addWidget(btnQuickAddCustomer);


        verticalLayout_9->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        labelPhoneTitle = new QLabel(frameCustomer);
        labelPhoneTitle->setObjectName("labelPhoneTitle");

        horizontalLayout_7->addWidget(labelPhoneTitle);

        labelCustomerPhone = new QLabel(frameCustomer);
        labelCustomerPhone->setObjectName("labelCustomerPhone");
        labelCustomerPhone->setStyleSheet(QString::fromUtf8("color: #666;"));

        horizontalLayout_7->addWidget(labelCustomerPhone);


        verticalLayout_9->addLayout(horizontalLayout_7);


        verticalLayoutRight->addWidget(frameCustomer);

        frameCart = new QFrame(tabNewRental);
        frameCart->setObjectName("frameCart");
        frameCart->setFrameShape(QFrame::StyledPanel);
        frameCart->setStyleSheet(QString::fromUtf8("\n"
"              QFrame {\n"
"                  background-color: white;\n"
"                  border-radius: 8px;\n"
"                  border: 1px solid #e0e0e0;\n"
"              }\n"
"             "));
        verticalLayout_11 = new QVBoxLayout(frameCart);
        verticalLayout_11->setObjectName("verticalLayout_11");
        labelCartTitle = new QLabel(frameCart);
        labelCartTitle->setObjectName("labelCartTitle");
        labelCartTitle->setStyleSheet(QString::fromUtf8("font-weight: bold; font-size: 14px;"));

        verticalLayout_11->addWidget(labelCartTitle);

        tableRentalCart = new QTableWidget(frameCart);
        if (tableRentalCart->columnCount() < 5)
            tableRentalCart->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableRentalCart->setHorizontalHeaderItem(0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableRentalCart->setHorizontalHeaderItem(1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableRentalCart->setHorizontalHeaderItem(2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableRentalCart->setHorizontalHeaderItem(3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableRentalCart->setHorizontalHeaderItem(4, __qtablewidgetitem28);
        tableRentalCart->setObjectName("tableRentalCart");
        tableRentalCart->setAlternatingRowColors(true);
        tableRentalCart->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_11->addWidget(tableRentalCart);

        frameTotalSection = new QFrame(frameCart);
        frameTotalSection->setObjectName("frameTotalSection");
        frameTotalSection->setStyleSheet(QString::fromUtf8("\n"
"                 QFrame {\n"
"                     background-color: #f5f5f5;\n"
"                     border-radius: 6px;\n"
"                     padding: 10px;\n"
"                 }\n"
"                "));
        horizontalLayout_8 = new QHBoxLayout(frameTotalSection);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        labelTotalText = new QLabel(frameTotalSection);
        labelTotalText->setObjectName("labelTotalText");
        labelTotalText->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold;"));

        horizontalLayout_8->addWidget(labelTotalText);

        spacerItem = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(spacerItem);

        labelRentalTotal = new QLabel(frameTotalSection);
        labelRentalTotal->setObjectName("labelRentalTotal");
        labelRentalTotal->setStyleSheet(QString::fromUtf8("font-size: 24px; font-weight: bold; color: #4CAF50;"));

        horizontalLayout_8->addWidget(labelRentalTotal);


        verticalLayout_11->addWidget(frameTotalSection);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        btnClearCart = new QPushButton(frameCart);
        btnClearCart->setObjectName("btnClearCart");
        btnClearCart->setMinimumHeight(40);

        horizontalLayout_9->addWidget(btnClearCart);

        btnProcessRental = new QPushButton(frameCart);
        btnProcessRental->setObjectName("btnProcessRental");
        btnProcessRental->setMinimumHeight(40);

        horizontalLayout_9->addWidget(btnProcessRental);


        verticalLayout_11->addLayout(horizontalLayout_9);


        verticalLayoutRight->addWidget(frameCart);


        horizontalLayoutMain->addLayout(verticalLayoutRight);

        tabWidget->addTab(tabNewRental, QString());
        tabRentals = new QWidget();
        tabRentals->setObjectName("tabRentals");
        verticalLayout_12 = new QVBoxLayout(tabRentals);
        verticalLayout_12->setSpacing(15);
        verticalLayout_12->setContentsMargins(20, 20, 20, 20);
        verticalLayout_12->setObjectName("verticalLayout_12");
        frameRentalFilter = new QFrame(tabRentals);
        frameRentalFilter->setObjectName("frameRentalFilter");
        frameRentalFilter->setFrameShape(QFrame::StyledPanel);
        frameRentalFilter->setStyleSheet(QString::fromUtf8("\n"
"            QFrame {\n"
"                background-color: white;\n"
"                border-radius: 8px;\n"
"                border: 1px solid #e0e0e0;\n"
"            }\n"
"           "));
        horizontalLayout_10 = new QHBoxLayout(frameRentalFilter);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        lineEditSearchRental = new QLineEdit(frameRentalFilter);
        lineEditSearchRental->setObjectName("lineEditSearchRental");
        lineEditSearchRental->setMinimumHeight(36);

        horizontalLayout_10->addWidget(lineEditSearchRental);

        btnViewRentalDetails = new QPushButton(frameRentalFilter);
        btnViewRentalDetails->setObjectName("btnViewRentalDetails");
        btnViewRentalDetails->setStyleSheet(QString::fromUtf8("background-color: #2196F3; color: white;"));
        btnViewRentalDetails->setMinimumHeight(36);

        horizontalLayout_10->addWidget(btnViewRentalDetails);

        btnDeleteRental = new QPushButton(frameRentalFilter);
        btnDeleteRental->setObjectName("btnDeleteRental");
        btnDeleteRental->setMinimumHeight(36);

        horizontalLayout_10->addWidget(btnDeleteRental);


        verticalLayout_12->addWidget(frameRentalFilter);

        tableRentals = new QTableWidget(tabRentals);
        if (tableRentals->columnCount() < 6)
            tableRentals->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableRentals->setHorizontalHeaderItem(0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableRentals->setHorizontalHeaderItem(1, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableRentals->setHorizontalHeaderItem(2, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableRentals->setHorizontalHeaderItem(3, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableRentals->setHorizontalHeaderItem(4, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableRentals->setHorizontalHeaderItem(5, __qtablewidgetitem34);
        tableRentals->setObjectName("tableRentals");
        tableRentals->setAlternatingRowColors(true);
        tableRentals->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableRentals->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableRentals->setSortingEnabled(true);

        verticalLayout_12->addWidget(tableRentals);

        tabWidget->addTab(tabRentals, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1400, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Vehicle Rental Management System", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save All", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load All", nullptr));
#if QT_CONFIG(shortcut)
        actionLoad->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        labelStatsTitle1->setText(QCoreApplication::translate("MainWindow", "Total Vehicles", nullptr));
        labelTotalVehicles->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelStatsTitle2->setText(QCoreApplication::translate("MainWindow", "Available", nullptr));
        labelAvailableVehicles->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelStatsTitle3->setText(QCoreApplication::translate("MainWindow", "Active Rentals", nullptr));
        labelActiveRentals->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelStatsTitle4->setText(QCoreApplication::translate("MainWindow", "Total Revenue", nullptr));
        labelTotalRevenue->setText(QCoreApplication::translate("MainWindow", "Rp 0", nullptr));
        labelRecentTitle->setText(QCoreApplication::translate("MainWindow", "Recent Rentals", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableRecentRentals->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableRecentRentals->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Customer", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableRecentRentals->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableRecentRentals->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Total Days", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableRecentRentals->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Total (Rp)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDashboard), QCoreApplication::translate("MainWindow", " Dashboard", nullptr));
        lineEditSearchVehicle->setPlaceholderText(QCoreApplication::translate("MainWindow", " Search by brand or model...", nullptr));
        comboBoxFilterType->setItemText(0, QCoreApplication::translate("MainWindow", "All Types", nullptr));
        comboBoxFilterType->setItemText(1, QCoreApplication::translate("MainWindow", "Car", nullptr));
        comboBoxFilterType->setItemText(2, QCoreApplication::translate("MainWindow", "Motorcycle", nullptr));

        comboBoxFilterAvailability->setItemText(0, QCoreApplication::translate("MainWindow", "All Status", nullptr));
        comboBoxFilterAvailability->setItemText(1, QCoreApplication::translate("MainWindow", "Available", nullptr));
        comboBoxFilterAvailability->setItemText(2, QCoreApplication::translate("MainWindow", "Rented", nullptr));

        btnAddVehicle->setText(QCoreApplication::translate("MainWindow", " Add Vehicle", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableVehicles->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableVehicles->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableVehicles->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Brand", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableVehicles->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Model", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableVehicles->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Extra Info", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableVehicles->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Daily Rate", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableVehicles->horizontalHeaderItem(6);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        btnEditVehicle->setText(QCoreApplication::translate("MainWindow", " Edit", nullptr));
        btnDeleteVehicle->setText(QCoreApplication::translate("MainWindow", "\357\270\217 Delete", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabVehicles), QCoreApplication::translate("MainWindow", " Vehicles", nullptr));
        lineEditSearchCustomer->setPlaceholderText(QCoreApplication::translate("MainWindow", " Search by name or phone...", nullptr));
        btnAddCustomer->setText(QCoreApplication::translate("MainWindow", " Add Customer", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableCustomers->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableCustomers->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableCustomers->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableCustomers->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "Total Rentals", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableCustomers->horizontalHeaderItem(4);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "Total Spent", nullptr));
        btnEditCustomer->setText(QCoreApplication::translate("MainWindow", "\357\270\217 Edit", nullptr));
        btnDeleteCustomer->setText(QCoreApplication::translate("MainWindow", "\357\270\217 Delete", nullptr));
        btnViewCustomerHistory->setText(QCoreApplication::translate("MainWindow", " View History", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCustomers), QCoreApplication::translate("MainWindow", " Customers", nullptr));
        labelAvailableTitle->setText(QCoreApplication::translate("MainWindow", "Available Vehicles", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableAvailableVehicles->horizontalHeaderItem(0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableAvailableVehicles->horizontalHeaderItem(1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableAvailableVehicles->horizontalHeaderItem(2);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "Brand", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableAvailableVehicles->horizontalHeaderItem(3);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "Model", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableAvailableVehicles->horizontalHeaderItem(4);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "Daily Rate", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableAvailableVehicles->horizontalHeaderItem(5);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "Days", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableAvailableVehicles->horizontalHeaderItem(6);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "Action", nullptr));
        labelCustomerTitle->setText(QCoreApplication::translate("MainWindow", "Customer", nullptr));
        btnQuickAddCustomer->setText(QCoreApplication::translate("MainWindow", " New", nullptr));
        labelPhoneTitle->setText(QCoreApplication::translate("MainWindow", "Phone:", nullptr));
        labelCustomerPhone->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        labelCartTitle->setText(QCoreApplication::translate("MainWindow", "Rental Cart", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableRentalCart->horizontalHeaderItem(0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "Vehicle", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableRentalCart->horizontalHeaderItem(1);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "Rate", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableRentalCart->horizontalHeaderItem(2);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "Days", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableRentalCart->horizontalHeaderItem(3);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "Subtotal", nullptr));
        labelTotalText->setText(QCoreApplication::translate("MainWindow", "TOTAL:", nullptr));
        labelRentalTotal->setText(QCoreApplication::translate("MainWindow", "Rp 0", nullptr));
        btnClearCart->setText(QCoreApplication::translate("MainWindow", " Clear Cart", nullptr));
        btnProcessRental->setText(QCoreApplication::translate("MainWindow", " Process Rental", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabNewRental), QCoreApplication::translate("MainWindow", " New Rental", nullptr));
        lineEditSearchRental->setPlaceholderText(QCoreApplication::translate("MainWindow", " Search by customer or ID...", nullptr));
        btnViewRentalDetails->setText(QCoreApplication::translate("MainWindow", " View Details", nullptr));
        btnDeleteRental->setText(QCoreApplication::translate("MainWindow", "\357\270\217 Delete", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableRentals->horizontalHeaderItem(0);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableRentals->horizontalHeaderItem(1);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "Customer", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableRentals->horizontalHeaderItem(2);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableRentals->horizontalHeaderItem(3);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "Vehicles", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableRentals->horizontalHeaderItem(4);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "Total Days", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableRentals->horizontalHeaderItem(5);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "Total", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabRentals), QCoreApplication::translate("MainWindow", " Rentals", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
