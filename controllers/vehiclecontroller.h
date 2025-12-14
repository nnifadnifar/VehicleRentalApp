#ifndef VEHICLECONTROLLER_H
#define VEHICLECONTROLLER_H

#include "../models/vehicle.h"
#include "../utils/datahandler.h"
#include <memory>
#include <vector>

// VehicleController TIDAK inherit dari IController
// Karena IController<Vehicle*> tidak compatible dengan unique_ptr management
class VehicleController {
private:
    std::vector<std::unique_ptr<Vehicle>> m_vehicle;
    DataHandler& m_dataHandler;
    static constexpr const char* FILENAME = "vehicle.txt";

public:
    explicit VehicleController(DataHandler& datahandler);
    ~VehicleController() = default;

    // CRUD operations (NOT using override)
    std::vector<Vehicle*> getAll() const;
    Vehicle* getById(int id);
    bool add(std::unique_ptr<Vehicle> vehicle);
    bool update(const Vehicle& vehicle);
    bool remove(int id);

    // File operations
    bool saveToFile();
    bool loadFromFile();

    // Count methods
    int getCount() const;
    int getCountByType(const std::string& type) const;

    // Additional methods
    std::vector<Vehicle*> getByType(const std::string& type) const;

    // Factory methods
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
};

#endif // VEHICLECONTROLLER_H
