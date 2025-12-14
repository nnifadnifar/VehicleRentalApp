#include "vehiclecontroller.h"
#include "../models/car.h"
#include "../models/motorcycle.h"
#include "../utils/idgenerator.h"
#include <algorithm>

VehicleController::VehicleController(DataHandler& dataHandler)
    : m_dataHandler(dataHandler)
{
}

std::vector<Vehicle*> VehicleController::getAll() const {
    std::vector<Vehicle*> result;
    result.reserve(m_vehicle.size());

    for (const auto& vehicle : m_vehicle) {
        result.push_back(vehicle.get());
    }

    return result;
}

Vehicle* VehicleController::getById(int id) {
    auto it = std::find_if(m_vehicle.begin(), m_vehicle.end(),
                           [id](const std::unique_ptr<Vehicle>& v) {
                               return v->getId() == id;
                           });

    if (it != m_vehicle.end()) {
        return it->get();
    }
    return nullptr;
}

std::vector<Vehicle*> VehicleController::getByType(const std::string& type) const {
    std::vector<Vehicle*> result;

    for (const auto& vehicle : m_vehicle) {
        if (vehicle->getVehicleType() == type) {
            result.push_back(vehicle.get());
        }
    }

    return result;
}

bool VehicleController::add(std::unique_ptr<Vehicle> vehicle) {
    if (!vehicle || !vehicle->isValid()) {
        return false;
    }

    // Check for duplicate ID
    if (getById(vehicle->getId()) != nullptr) {
        return false;
    }

    // Update ID generator
    IdGenerator::getInstance().updateCounter("vehicle", vehicle->getId());

    m_vehicle.push_back(std::move(vehicle));
    return true;
}

bool VehicleController::update(const Vehicle& vehicle) {
    Vehicle* existing = getById(vehicle.getId());
    if (!existing) {
        return false;
    }

    // Update common fields
    existing->setBrand(vehicle.getBrand());
    existing->setModel(vehicle.getModel());
    existing->setDailyRate(vehicle.getDailyRate());
    existing->setAvailable(vehicle.isAvailable());
    existing->setExtraField(vehicle.getExtraField());

    return true;
}

bool VehicleController::remove(int id) {
    auto it = std::find_if(m_vehicle.begin(), m_vehicle.end(),
                           [id](const std::unique_ptr<Vehicle>& v) {
                               return v->getId() == id;
                           });

    if (it != m_vehicle.end()) {
        m_vehicle.erase(it);
        return true;
    }
    return false;
}

std::unique_ptr<Vehicle> VehicleController::createMotorcycle(
    int id,
    const std::string& brand,
    const std::string& model,
    const std::string& category,
    double dailyRate,
    bool isAvailable)
{
    return std::make_unique<Motorcycle>(id, brand, model, category, dailyRate, isAvailable);
}

std::unique_ptr<Vehicle> VehicleController::createCar(
    int id,
    const std::string& brand,
    const std::string& model,
    const std::string& type,
    double dailyRate,
    bool isAvailable)
{
    return std::make_unique<Car>(id, brand, model, type, dailyRate, isAvailable);
}

bool VehicleController::saveToFile() {
    std::vector<std::string> lines;
    lines.reserve(m_vehicle.size());

    for (const auto& vehicle : m_vehicle) {
        // Save with type prefix: "car:" or "motorcycle:"
        std::string line = vehicle->getVehicleType() + ":" + vehicle->serialize();
        lines.push_back(line);
    }

    return m_dataHandler.writeLines(FILENAME, lines);
}

bool VehicleController::loadFromFile() {
    m_vehicle.clear();

    std::vector<std::string> lines = m_dataHandler.readLines(FILENAME);

    for (const auto& line : lines) {
        if (line.empty()) continue;

        // Split type prefix
        size_t colonPos = line.find(':');
        if (colonPos == std::string::npos) continue;

        std::string type = line.substr(0, colonPos);
        std::string data = line.substr(colonPos + 1);

        std::unique_ptr<Vehicle> vehicle;

        if (type == "car") {
            vehicle = std::make_unique<Car>();
        } else if (type == "motorcycle") {
            vehicle = std::make_unique<Motorcycle>();
        } else {
            continue; // Unknown type
        }

        vehicle->deserialize(data);

        if (vehicle->isValid()) {
            IdGenerator::getInstance().updateCounter("vehicle", vehicle->getId());
            m_vehicle.push_back(std::move(vehicle));
        }
    }

    return true;
}

int VehicleController::getCount() const {
    return static_cast<int>(m_vehicle.size());
}

int VehicleController::getCountByType(const std::string& type) const {
    int count = 0;
    for (const auto& vehicle : m_vehicle) {
        if (vehicle->getVehicleType() == type) {
            count++;
        }
    }
    return count;
}
