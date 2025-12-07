#include "transactiondays.h"
#include "../utils/datahandler.h"
#include <sstream>
#include <stdexcept>

TransactionDays::TransactionDays()
    : m_vehicleId(0)
    , m_vehicleName("")
    , m_dailyRate(0.0)
    , m_rentalDays(0)
    , m_startDate("")
    , m_endDate("")
{
}

TransactionDays::TransactionDays(int vehicleId, const std::string& vehicleName,
                                 double dailyRate, int rentalDays,
                                 const std::string& startDate, const std::string& endDate)
    : m_vehicleId(vehicleId)
    , m_vehicleName(vehicleName)
    , m_dailyRate(dailyRate)
    , m_rentalDays(rentalDays)
    , m_startDate(startDate)
    , m_endDate(endDate)
{
}

int TransactionDays::getVehicleId() const{
    return m_vehicleId;
}

std::string TransactionDays::getVehicleName() const{
    return m_vehicleName;
}

double TransactionDays::getDailyRate() const{
    return m_dailyRate;
}

std::string TransactionDays::getStartDate() const{
    return m_startDate;
}

std::string TransactionDays::getEndDate() const{
    return m_endDate;
}

int TransactionDays::getRentalDays() const{
    return m_rentalDays;
}

double TransactionDays::getSubtotal() const{
    return m_dailyRate * m_rentalDays;
}

//getters

void TransactionDays::setVehicleId(int id){
    m_vehicleId = id;
}

void TransactionDays::setVehicleName(const std::string& name){
    m_vehicleName = name;
}

void TransactionDays::setDailyRate(double rate){
    if (rate >= 0){
        m_dailyRate = rate;
    }
}

void TransactionDays::setRentalDays(int days){
    if (days >= 0){
        m_rentalDays = days;
    }
}

void TransactionDays::setStartDate(const std::string& date){
    m_startDate = date;
}

void TransactionDays::setEndDate(const std::string& date){
    m_endDate = date;
}

void TransactionDays::extendRentalDays(int days){
    if (days > 0){
        m_rentalDays += days;
    }
}

bool TransactionDays::reduceRentalDays(int days) {
    if (days > 0 && m_rentalDays > days) {
        m_rentalDays -= days;
        return true;
    }
    return false;
}

std::string TransactionDays::serializeCompact() const {
    std::ostringstream oss;
    oss << m_vehicleId << ":" << m_rentalDays;
    return oss.str();
}

void TransactionDays::deserializeCompact(const std::string& data) {
    std::vector<std::string> parts = DataHandler::splitLine(data, ':');
    if (parts.size() >= 2) {
        m_vehicleId = std::stoi(parts[0]);
        m_rentalDays = std::stoi(parts[1]);
    }
}


