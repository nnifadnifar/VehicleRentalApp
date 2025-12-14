#include "rentalcontroller.h"
#include "../utils/IdGenerator.h"
#include <algorithm>

RentalController::RentalController(DataHandler& dataHandler)
    : m_dataHandler(dataHandler)
{
}

std::vector<Transaction> RentalController::getAll() const {
    return m_transactions;
}

Transaction* RentalController::getById(int id) {
    auto it = std::find_if(m_transactions.begin(), m_transactions.end(),
                           [id](const Transaction& t) {
                               return t.getId() == id;
                           });

    if (it != m_transactions.end()) {
        return &(*it);
    }
    return nullptr;
}

bool RentalController::add(const Transaction& transaction) {
    if (!transaction.isValid()) {
        return false;
    }

    // Check for duplicate ID
    if (getById(transaction.getId()) != nullptr) {
        return false;
    }

    // Update ID generator
    IdGenerator::getInstance().updateCounter("transaction", transaction.getId());

    m_transactions.push_back(transaction);
    return true;
}

bool RentalController::update(const Transaction& transaction) {
    Transaction* existing = getById(transaction.getId());
    if (!existing) {
        return false;
    }

    // Update the transaction
    *existing = transaction;
    return true;
}

bool RentalController::remove(int id) {
    auto it = std::find_if(m_transactions.begin(), m_transactions.end(),
                           [id](const Transaction& t) {
                               return t.getId() == id;
                           });

    if (it != m_transactions.end()) {
        m_transactions.erase(it);
        return true;
    }
    return false;
}

bool RentalController::saveToFile() {
    std::vector<std::string> lines;
    lines.reserve(m_transactions.size());

    for (const auto& transaction : m_transactions) {
        lines.push_back(transaction.serialize());
    }

    return m_dataHandler.writeLines(FILENAME, lines);
}

bool RentalController::loadFromFile() {
    m_transactions.clear();

    std::vector<std::string> lines = m_dataHandler.readLines(FILENAME);

    for (const auto& line : lines) {
        if (line.empty()) continue;

        Transaction transaction;
        transaction.deserialize(line);

        if (transaction.isValid()) {
            IdGenerator::getInstance().updateCounter("transaction", transaction.getId());
            m_transactions.push_back(transaction);
        }
    }

    return true;
}

int RentalController::getCount() const {
    return static_cast<int>(m_transactions.size());
}

Transaction RentalController::createTransaction(int customerId) {
    int id = IdGenerator::getInstance().getNextId("transaction");
    return Transaction(id, customerId);
}

std::vector<Transaction*> RentalController::getByCustomerId(int customerId) {
    std::vector<Transaction*> results;

    for (auto& transaction : m_transactions) {
        if (transaction.getCustomerId() == customerId) {
            results.push_back(&transaction);
        }
    }

    return results;
}

std::vector<Transaction*> RentalController::getByDateRange(const std::string& startDate, const std::string& endDate) {
    std::vector<Transaction*> results;

    for (auto& transaction : m_transactions) {
        std::string transactionDate = transaction.getDateTime();

        // Simple string comparison (works for YYYY-MM-DD format)
        if (transactionDate >= startDate && transactionDate <= endDate) {
            results.push_back(&transaction);
        }
    }

    return results;
}

double RentalController::getTotalRevenue() const {
    double total = 0.0;
    for (const auto& transaction : m_transactions) {
        total += transaction.getSubtotal();
    }
    return total;
}

double RentalController::getRevenueByCustomer(int customerId) const {
    double total = 0.0;
    for (const auto& transaction : m_transactions) {
        if (transaction.getCustomerId() == customerId) {
            total += transaction.getSubtotal();
        }
    }
    return total;
}

int RentalController::getTotalRentalDays() const {
    int total = 0;
    for (const auto& transaction : m_transactions) {
        total += transaction.getTotalDays();
    }
    return total;
}

std::vector<Transaction*> RentalController::getActiveRentals() {
    std::vector<Transaction*> results;

    for (auto& transaction : m_transactions) {
        if (transaction.hasDays()) {
            results.push_back(&transaction);
        }
    }

    return results;
}

bool RentalController::hasActiveRental(int customerId) const {
    for (const auto& transaction : m_transactions) {
        if (transaction.getCustomerId() == customerId && transaction.hasDays()) {
            return true;
        }
    }
    return false;
}
