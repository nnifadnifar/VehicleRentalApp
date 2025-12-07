#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "IEntity.h"
#include "transactiondays.h"
#include <vector>
#include <string>

class Transaction : public IEntity{
private:
    int m_id;
    int m_customerId;
    std::string m_dateTime;
    std::vector<TransactionDays> m_days;
    double m_subtotal;

public:
    Transaction();
    Transaction(int id,int customerId = 0);

    virtual ~Transaction() = default;

    int getId() const override;
    std::string serialize() const override;
    void deserialize(const std::string& data) override;
    bool isValid() const override;

    int getCustomerId() const;
    std::string getDateTime() const;
    const std::vector<TransactionDays>& getDays() const;
    double getSubtotal() const;
    int getTotalDays() const;

    void setId(int id);
    void setCustomerId(int customerId);
    void setDateTime(const std::string& dateTime);

    void addDay(const TransactionDays& days);
    bool removeDay(int productId);
    bool updateDaysDuration(int vehicleId, int days);

    TransactionDays* getDay(int vehicleId);
    void clearDays();
    bool hasDays() const;

    void recalculate();
    void setCurrentDateTime();
    std::string serializeDays() const;
    void deserializeDays(const std::string& data);
};
#endif // TRANSACTION_H
