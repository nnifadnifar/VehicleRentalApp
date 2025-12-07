#ifndef VEHICLECONTROLLER_H
#define VEHICLECONTROLLER_H

#include "Icontroller.h"
#include "../models/vehicle.h"
#include "../utils/datahandler.h"
#include <memory>
#include <vector>

class VehicleController{
private:
    std::vector<std::unique_ptr<Vehicle>> m_vehicle;
    DataHandler& m_dataHandler;
    static constexpr const char* FILENAME = "vehicle.txt";

public:
    explicit VehicleController(DataHandler& datahandler);
    ~VehicleController() = default;

    std::vector<Vehicle*> getAll() const;

    Vehicle* getById(int id);

    std::vector<Vehicle*> getByType(const std::string& type) const;
    bool add(std::unique_ptr<Vehicle> vehicle);
    bool update(const Vehicle& vehicle);
    bool remove(int id);
    std::unique_ptr<Vehicle> createMotorcycle(int id,
                                              const std::string& brand,
                                              const std::string& model,
                                              const std::string& category = "standard",
                                              double dailyRate = 0.0,
                                              bool isAvailable = true);

    std::unique_ptr<Vehicle> createCar(int id,
                                       const std::string& brand,
                                       const std::string& model,
                                       const std::string& type = "Manual",
                                       double dailyRate = 0.0,
                                       bool isAvailable = true);

    // ============ File I/O ============


    bool saveToFile();
    bool loadFromFile();
    int getCount() const;
    int getCountByType(const std::string& type) const;
};

#endif // VEHICLECONTROLLER_H
