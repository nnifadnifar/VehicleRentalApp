#include "Motorcycle.h"
#include <sstream>
#include "../utils/datahandler.h"
#include <iomanip>

Motorcycle::Motorcycle()
    : Vehicle()
    , m_category("standard")
{
    m_vehicleType = "motorcycle";
}

Motorcycle::Motorcycle(int id, const std::string& brand, const std::string& model, const std::string& category, double dailyRate, bool isAvailable)
    : Vehicle(id, brand, model,"motorcycle", dailyRate, isAvailable)
    , m_category(category)
{
}

std::string Motorcycle::getCategory() const{
    return m_category;
}

void Motorcycle::setCategory(const std::string& category){
    m_category = category;
}
std::string Motorcycle::serialize() const {
    std::ostringstream oss;
    oss << m_id << "|"
        << m_brand << "|"
        << m_model << "|"
        << std::fixed << std::setprecision(2) << m_category << m_dailyRate << "|" << m_isAvailable;
    return oss.str();
}

void Motorcycle::deserialize(const std::string& data) {
    std::vector<std::string> fields = DataHandler::splitLine(data, '|');

    if (fields.size() >= 6) {
        m_id = std::stoi(fields[0]);
        m_brand = fields[1];
        m_model = (fields[2]);
        m_category = (fields[3]);
        m_dailyRate = std::stod(fields[4]);
        m_isAvailable = (fields[5]== "1");
    }
}

std::string Motorcycle::getDescription() const {
    return m_brand + " " + m_model + " (" + m_category + ")";
}

std::string Motorcycle::getExtraField() const {
    return m_category;
}

void Motorcycle::setExtraField(const std::string& value) {
    m_category = value;
}

Vehicle* Motorcycle::clone() const {
    return new Motorcycle(*this);
}
