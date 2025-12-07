#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "vehicle.h"

class Motorcycle : public Vehicle {
private:
    std::string m_category; ///< category: "standard", "sport", "other"

public:
    Motorcycle();
    Motorcycle(int id,
               const std::string& brand,
               const std::string& model,
               const std::string& category = "standard",
               double dailyRate = 0.0,
               bool isAvailable = true);

    virtual ~Motorcycle() = default;

    std::string serialize() const override;
    void deserialize(const std::string& data) override;

    std::string getDescription() const override;
    std::string getExtraField() const override;
    void setExtraField(const std::string& value) override;
    Vehicle* clone() const override;

    std::string getCategory() const;
    void setCategory(const std::string& category);

};

#endif // MOTORCYCLE_H
