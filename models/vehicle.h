#ifndef VEHICLE_H
#define VEHICLE_H

#include "IEntity.h"
#include <string>

class Vehicle : public IEntity{
protected:
    int m_id;
    std::string m_brand;
    std::string m_model;
    std::string m_vehicleType;
    double m_dailyRate;
    bool m_isAvailable;

public:
    Vehicle();
    Vehicle(int id, const std::string& brand, const std::string& model, const std::string& vehicleType, double dailyRate, bool isAvailable = true);

    virtual ~Vehicle() = default;

    int getId() const override;
    bool isValid() const override;



    // ============ Getters ============


    std::string getBrand() const;
    std::string getModel() const;
    std::string getVehicleType() const;
    double getDailyRate() const;
    bool isAvailable() const;

    // ============ Setters ============


    void setId(int id);
    void setBrand(const std::string& brand);
    void setModel(const std::string& model);
    void setDailyRate(double rate);
    void setAvailable(bool available);


    virtual std::string getDescription() const = 0;
    virtual double calculateRentalCost(int days) const;
    virtual std::string getExtraField() const = 0;
    virtual void setExtraField(const std::string& value) = 0;
    virtual Vehicle* clone() const = 0;
};

#endif // VEHICLE_H
