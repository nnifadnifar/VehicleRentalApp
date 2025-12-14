#ifndef RENTALCONTROLLER_H
#define RENTALCONTROLLER_H

#include "Icontroller.h"
#include "../models/transaction.h"
#include "../utils/datahandler.h"
#include <vector>
#include <memory>

class RentalController : public IController<Transaction> {
private:
    std::vector<Transaction> m_transactions;
    DataHandler& m_dataHandler;
    static constexpr const char* FILENAME = "rental.txt";

public:
    explicit RentalController(DataHandler& dataHandler);
    ~RentalController() = default;

    // IController interface
    std::vector<Transaction> getAll() const override;
    Transaction* getById(int id) override;
    bool add(const Transaction& transaction) override;
    bool update(const Transaction& transaction) override;
    bool remove(int id) override;
    bool saveToFile() override;
    bool loadFromFile() override;
    int getCount() const override;

    // Rental-specific methods
    Transaction createTransaction(int customerId);
    std::vector<Transaction*> getByCustomerId(int customerId);
    std::vector<Transaction*> getByDateRange(const std::string& startDate, const std::string& endDate);

    // Statistics
    double getTotalRevenue() const;
    double getRevenueByCustomer(int customerId) const;
    int getTotalRentalDays() const;

    // Active rentals (transactions with items)
    std::vector<Transaction*> getActiveRentals();
    bool hasActiveRental(int customerId) const;
};

#endif // RENTALCONTROLLER_H
