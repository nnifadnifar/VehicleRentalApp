#ifndef TRANSACTIONDAYS_H
#define TRANSACTIONDAYS_H

#include <string>

class TransactionDays {
private:
    int m_vehicleId;          ///< Vehicle ID reference
    std::string m_vehicleName; ///< Vehicle name (stored for history)
    double m_dailyRate;        ///< Price per day at time of rental
    int m_rentalDays;          ///< Number of rental days
    std::string m_startDate;   ///< Rental start date (YYYY-MM-DD)
    std::string m_endDate;     ///< Rental end date (YYYY-MM-DD)

public:
    TransactionDays();

    TransactionDays(int vehicleId, const std::string& vehicleName,
                    double dailyRate, int rentalDays,
                    const std::string& startDate, const std::string& endDate);

    // ============ Getters ============

    int getVehicleId() const;
    std::string getVehicleName() const;
    double getDailyRate() const;
    int getRentalDays() const;
    std::string getStartDate() const;
    std::string getEndDate() const;

    double getSubtotal() const;

    // ============ Setters ============

    void setVehicleId(int id);
    void setVehicleName(const std::string& name);
    void setDailyRate(double rate);
    void setRentalDays(int days);
    void setStartDate(const std::string& date);
    void setEndDate(const std::string& date);


    void extendRentalDays(int days = 1);
    bool reduceRentalDays(int days = 1);

    // ============ Serialization ============


    std::string serializeCompact() const;
    void deserializeCompact(const std::string& data);

    bool isValid() const;
};

#endif // TRANSACTIONDAYS_H
