#ifndef PRODUCTVIEW_H
#define PRODUCTVIEW_H

#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include "../controllers/vehiclecontroller.h"

class ProductView : public QWidget
{
    Q_OBJECT

public:
    explicit ProductView(QWidget* parent, VehicleController* vehicleController);
    ~ProductView() = default;

    void setupUi(QTableWidget* table,
                 QLineEdit* searchEdit,
                 QComboBox* filterType,
                 QComboBox* filterAvailability,
                 QPushButton* btnAdd,
                 QPushButton* btnEdit,
                 QPushButton* btnDelete);

    void loadData();
    void refresh();

signals:
    void dataChanged();

private slots:
    void onAddVehicle();
    void onEditVehicle();
    void onDeleteVehicle();
    void onSearchVehicle(const QString& text);
    void onFilterType(int index);
    void onFilterAvailability(int index);

private:
    VehicleController* m_vehicleController;

    QTableWidget* m_table;
    QLineEdit* m_searchEdit;
    QComboBox* m_filterType;
    QComboBox* m_filterAvailability;
    QPushButton* m_btnAdd;
    QPushButton* m_btnEdit;
    QPushButton* m_btnDelete;

    void loadVehiclesTable();
    void applyFilters();
    int getSelectedVehicleId();
};

#endif // PRODUCTVIEW_H
