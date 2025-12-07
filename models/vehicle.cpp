#include "Vehicle.h"

// ============ Constructors ============

Vehicle::Vehicle()
    : m_id(0)
    , m_brand("")
    , m_model("")
    , m_vehicleType("")
    , m_dailyRate(0.0)
    , m_isAvailable(true)
{
}

Vehicle::Vehicle(int id, const std::string& brand, const std::string& model, const std::string& vehicleType,double dailyRate, bool isAvailable)
    : m_id(id)
    , m_brand(brand)
    , m_model(model)
    , m_vehicleType(vehicleType)
    , m_dailyRate(dailyRate)
    , m_isAvailable(isAvailable)
{
}

// ============ IEntity Implementation ============


int Vehicle::getId() const {
    return m_id;
}
void Vehicle::setId(int id) {
    m_id = id;
}

// ============ Getters ============


std::string Vehicle::getBrand() const {
    return m_brand;
}
std::string Vehicle::getModel() const {
    return m_model;
}
std::string Vehicle::getVehicleType() const {
    return m_vehicleType;
}
double Vehicle::getDailyRate() const {
    return m_dailyRate;
}
bool Vehicle::isAvailable() const {
    return m_isAvailable;
}

// ============ Setters ============

void Vehicle::setBrand(const std::string& brand) {
    m_brand = brand;
}
void Vehicle::setModel(const std::string& model) {
    m_model = model;
}
void Vehicle::setDailyRate(double rate) {
    if (rate >= 0) {
        m_dailyRate = rate;
    }
}
void Vehicle::setAvailable(bool available) {
    m_isAvailable = available;
}
double Vehicle::calculateRentalCost(int days) const {
    if (days <= 0) {
        return 0.0;
    }
    return m_dailyRate * days;
}

bool Vehicle::isValid() const {
    return m_id > 0
           && !m_brand.empty()
           && !m_model.empty()
           && !m_vehicleType.empty()
           && m_dailyRate >= 0;
}
