#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "IEntity.h"
#include <string>


class Customer : public IEntity {
private:
    int m_id;
    std::string m_name;
    std::string m_phone;

public:
    Customer();
    Customer(int id, const std::string& name,const std::string& phone);

    virtual ~Customer() = default;

    //IEntity interface
    int getId() const override;
    std::string serialize() const override;
    void deserialize(const std::string& data) override;
    bool isValid() const override;

    //Getters
    std::string getName() const;
    std::string getPhone() const;

    //setters
    void setId(int id);
    void setName(const std::string& name);
    void setPhone(const std::string& phone);


};

#endif // CUSTOMER_H
