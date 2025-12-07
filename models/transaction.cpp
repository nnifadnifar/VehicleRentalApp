#include "transaction.h"
#include "customer.h"
#include "../utils/datahandler.h"
#include <sstream>
#include <chrono>
#include <iomanip>
#include <algorithm>

Transaction::Transaction()
    : m_id(0)
    , m_customerId(0)
    , m_dateTime("")
    , m_subtotal(0.0)

{
}

Transaction::Transaction(int id, int customerId)
    : m_id(id)
    , m_customerId(customerId)
    , m_dateTime("")
    , m_subtotal(0.0)
{
    setCurrentDateTime();
}

int Transaction::getId() const{
    return m_id;
}

std::string Transaction::serialize() const{
    std::ostringstream oss;
    oss << m_id << "|"
        << m_customerId << "|"
        << m_dateTime << "|"
        << std::fixed << std::setprecision(0) << m_subtotal << "|"
        << serializeDays();
    return oss.str();
}

void Transaction::deserialize(const std::string& data){
    std::vector<std::string> fields = DataHandler::splitLine(data, '|');

    if (fields.size() >= 5){
        m_id = std::stoi(fields[0]);
        m_customerId = std::stoi(fields[1]);
        m_dateTime = fields[2];
        m_subtotal = std::stod(fields[3]);
        deserializeDays(fields[4]);
    }
}

bool Transaction::isValid() const{
    return m_id > 0 && !m_days.empty();

}
int Transaction::getCustomerId() const {
    return m_customerId;
}

std::string Transaction::getDateTime() const {
    return m_dateTime;
}

const std::vector<TransactionDays>& Transaction::getDays() const {
    return m_days;
}

double Transaction::getSubtotal() const {
    return m_subtotal;
}

int Transaction::getTotalDays() const {
    int count = 0;
    for (const auto& day : m_days) {
        count += day.getRentalDays();
    }
    return count;
}

void Transaction::setId(int id) {
    m_id = id;
}

void Transaction::setCustomerId(int customerId) {
    m_customerId = customerId;
}

void Transaction::setDateTime(const std::string& dateTime) {
    m_dateTime = dateTime;
}


void Transaction::addDay(const TransactionDays& day) {
    // Check if product already exists
    for (const auto& existingDay : m_days) {
        if (existingDay.getVehicleId() == day.getVehicleId()) {
            return;
        }
    }

    // Add new item
    m_days.push_back(day);
    recalculate();
}

bool Transaction::removeDay(int vehicleId) {
    auto it = std::find_if(m_days.begin(), m_days.end(),
                           [vehicleId](const TransactionDays& day) {
                               return day.getVehicleId() == vehicleId;
                           });

    if (it != m_days.end()) {
        m_days.erase(it);
        recalculate();
        return true;
    }
    return false;
}

bool Transaction::updateDaysDuration(int vehicleId, int rentalDays) {
    if (rentalDays <= 0) {
        return removeDay(vehicleId);
    }

    // Find and update
    for (auto& day : m_days) {
        if (day.getVehicleId() == vehicleId) {
            day.setRentalDays(rentalDays);
            recalculate();
            return true;
        }
    }

    return false;
}

TransactionDays* Transaction::getDay(int vehicleId) {
    for (auto& day : m_days) {
        if (day.getVehicleId() == vehicleId) {
            return &day;
        }
    }
    return nullptr;
}

void Transaction::clearDays() {
    m_days.clear();
    recalculate();
}

bool Transaction::hasDays() const {
    return !m_days.empty();
}

void Transaction::recalculate() {
    // Calculate subtotal
    m_subtotal = 0.0;
    for (const auto& day : m_days) {
        m_subtotal += day.getSubtotal();
    }
}

void Transaction::setCurrentDateTime() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
    m_dateTime = oss.str();
}

std::string Transaction::serializeDays() const {
    if (m_days.empty()) {
        return "";
    }

    std::ostringstream oss;
    for (size_t i = 0; i < m_days.size(); ++i) {
        if (i > 0) {
            oss << ",";
        }
        oss << m_days[i].serializeCompact();
    }
    return oss.str();
}

void Transaction::deserializeDays(const std::string& data) {
    m_days.clear();

    if (data.empty()) {
        return;
    }

    // Split by comma
    std::vector<std::string> dayStrings = DataHandler::splitLine(data, ',');

    for (const auto& dayStr : dayStrings) {
        TransactionDays day;
        day.deserializeCompact(dayStr);
        if (day.getVehicleId() > 0) {
            m_days.push_back(day);
        }
    }
}

