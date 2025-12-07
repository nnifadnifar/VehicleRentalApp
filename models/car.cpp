#include "car.h"
#include "../utils/datahandler.h"
#include <sstream>

Car::Car()
    : Vehicle()
    , m_type("manual")
{
    m_vehicleType = "car";
}

Car::Car(int id, const std::string& brand, const std::string& model, const std::string& type, double dailyRate , bool isAvailable)
    : Vehicle(id, brand, model, "car", dailyRate, isAvailable )
    , m_type(type)
{
}

std::string Car::serialize() const{
    std::ostringstream oss;
    oss << m_id << "|"
        << m_brand << "|"
        << m_model << "|"
        << m_type << "|"
        << m_dailyRate<< "|"
        << m_isAvailable;
    return oss.str();
}
void Car::deserialize(const std::string& data){
    std::vector<std::string> fields = DataHandler::splitLine(data, '|');

    if(fields.size() >= 6){
        m_id = std::stoi(fields[0]);
        m_brand = fields[1];
        m_model = fields[2];
        m_type = fields[3];
        m_dailyRate = std::stod(fields[4]);
        m_isAvailable = (fields[5]== "1");
    }
}

std::string Car::getDescription()const {
    return m_brand + m_model + "(" + m_type + ")";
}

std::string Car::getExtraField() const{
    return m_type;
}

void Car::setExtraField(const std::string& value){
    m_type = value;
}

Vehicle* Car::clone() const{
    return  new Car(*this);
}

std::string Car::getType() const{
    return m_type;
}

void Car::setType(const std::string& type){
    m_type = type;
}
