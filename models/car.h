#ifndef CAR_H
#define CAR_H

#include "vehicle.h"


class Car : public Vehicle{
private:
    std::string m_type; ///< type : "Manual", "Matic"

public:
    Car();
    Car(int id,
        const std::string& brand,
        const std::string& model,
        const std::string& type = "Manual",
        double dailyRate = 0.0,
        bool isAvailable = true);

    virtual ~Car() = default;

    std::string serialize() const override;
    void deserialize(const std::string& data) override;

    std::string getDescription() const override;
    std::string getExtraField() const override;

    void setExtraField(const std::string& value) override;
    Vehicle* clone() const override;

    std::string getType() const;
    void setType(const std::string& type);
};

#endif // CAR_H
