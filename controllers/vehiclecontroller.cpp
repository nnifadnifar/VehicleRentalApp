#include "vehiclecontroller.h"
#include "../models/customer.h"
#include "../models//car.h"
#include "../utils/idgenerator.h"
#include <algorithm>

VehicleController::VehicleController(DataHandler& dataHandler)
    : m_dataHandler(dataHandler)
{
}

std::vector<Vehicle*> VehicleController::getAll() const {
    std::vector<Vehicle*> result;
    result.reserve(m_vehicle.size());

    for (const auto& product : m_vehicle) {
        result.push_back(product.get());
    }

    return result;
}

Vehicle* VehicleController::getById(int id) {
    auto it = std::find_if(m_vehicle.begin(), m_vehicle.end(),
                           [id](const std::unique_ptr<Vehicle>& p) {
                               return p->getId() == id;
                           });

    if (it != m_vehicle.end()) {
        return it->get();
    }
    return nullptr;
}

