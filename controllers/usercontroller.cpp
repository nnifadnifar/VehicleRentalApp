#include "usercontroller.h"
#include "../utils/IdGenerator.h"
#include <algorithm>

UserController::UserController(DataHandler& dataHandler)
    : m_dataHandler(dataHandler)
{
}

std::vector<Customer> UserController::getAll() const {
    return m_customers;
}

Customer* UserController::getById(int id) {
    auto it = std::find_if(m_customers.begin(), m_customers.end(),
                           [id](const Customer& c) {
                               return c.getId() == id;
                           });

    if (it != m_customers.end()) {
        return &(*it);
    }
    return nullptr;
}

bool UserController::add(const Customer& customer) {
    if (!customer.isValid()) {
        return false;
    }

    // Check for duplicate ID
    if (getById(customer.getId()) != nullptr) {
        return false;
    }

    // Update ID generator
    IdGenerator::getInstance().updateCounter("customer", customer.getId());

    m_customers.push_back(customer);
    return true;
}

bool UserController::update(const Customer& customer) {
    Customer* existing = getById(customer.getId());
    if (!existing) {
        return false;
    }

    existing->setName(customer.getName());
    existing->setPhone(customer.getPhone());
    return true;
}

bool UserController::remove(int id) {
    auto it = std::find_if(m_customers.begin(), m_customers.end(),
                           [id](const Customer& c) {
                               return c.getId() == id;
                           });

    if (it != m_customers.end()) {
        m_customers.erase(it);
        return true;
    }
    return false;
}

bool UserController::saveToFile() {
    std::vector<std::string> lines;
    lines.reserve(m_customers.size());

    for (const auto& customer : m_customers) {
        lines.push_back(customer.serialize());
    }

    return m_dataHandler.writeLines(FILENAME, lines);
}

bool UserController::loadFromFile() {
    m_customers.clear();

    std::vector<std::string> lines = m_dataHandler.readLines(FILENAME);

    for (const auto& line : lines) {
        if (line.empty()) continue;

        Customer customer;
        customer.deserialize(line);

        if (customer.isValid()) {
            IdGenerator::getInstance().updateCounter("customer", customer.getId());
            m_customers.push_back(customer);
        }
    }

    return true;
}

int UserController::getCount() const {
    return static_cast<int>(m_customers.size());
}

Customer UserController::createCustomer(const std::string& name, const std::string& phone) {
    int id = IdGenerator::getInstance().getNextId("customer");
    return Customer(id, name, phone);
}

std::vector<Customer*> UserController::searchName(const std::string& searchTerm) {
    std::vector<Customer*> results;

    // Convert search term to lowercase for case-insensitive search
    std::string lowerSearch = searchTerm;
    std::transform(lowerSearch.begin(), lowerSearch.end(), lowerSearch.begin(), ::tolower);

    for (auto& customer : m_customers) {
        std::string lowerName = customer.getName();
        std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

        if (lowerName.find(lowerSearch) != std::string::npos) {
            results.push_back(&customer);
        }
    }

    return results;
}

Customer* UserController::getByPhone(const std::string& phone) {
    auto it = std::find_if(m_customers.begin(), m_customers.end(),
                           [&phone](const Customer& c) {
                               return c.getPhone() == phone;
                           });

    if (it != m_customers.end()) {
        return &(*it);
    }
    return nullptr;
}
