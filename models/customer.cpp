#include "Customer.h"
#include "../utils/datahandler.h"
#include <sstream>

Customer::Customer()
    :m_id(0), m_name(""), m_phone("")
{
}

Customer::Customer(int id, const std::string& name, const std::string& phone)
    : m_id(id), m_name(name), m_phone(phone)
{
}

int Customer::getId() const {
    return m_id;
}

std::string Customer::getName() const {
    return m_name;
}

std::string Customer::getPhone() const {
    return m_phone;
}

void Customer::setId(int id) {
    m_id = id;
}
void Customer::setName(const std::string& name) {
    m_name = name;
}
void Customer::setPhone(const std::string& phone) {
    m_phone = phone;
}

std::string Customer::serialize() const {
    std::ostringstream oss;
    oss << m_id << "|" << m_name << "|" << m_phone;
    return oss.str();
}

void Customer::deserialize(const std::string& data){
    std::vector<std::string> fields = DataHandler::splitLine(data, '|');
    if (fields.size() >= 3){
        m_id = std::stoi(fields[0]);
        m_name = fields[1];
        m_phone = fields[2];
    }
}

bool Customer::isValid() const {
    return m_id > 0 && !m_name.empty();
}
