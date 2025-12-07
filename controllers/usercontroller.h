#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "Icontroller.h"
#include "../models/customer.h"
#include "../utils/datahandler.h"
#include <vector>

class UserController : public IController<Customer>{
private:
    std::vector<Customer> m_customers;
    DataHandler& m_dataHandler;
    static constexpr const char* FILENAME = "customer.txt";

public:
    explicit UserController(DataHandler& dataHandler);

    ~UserController()  = default;

    std::vector<Customer> getAll() const override;
    Customer* getById(int id) override;
    bool add(const Customer& customer) override;
    bool update(const Customer& customer) override;
    bool remove(int id) override;
    bool saveToFile() override;
    bool loadFromFile() override;
    int getCount() const override;

    Customer createCustomer(const std::string& name, const std::string& phone);
    std::vector<Customer*> searchName(const std::string& searchTerm);
    Customer* getByPhone(const std::string& phone);


};

#endif // USERCONTROLLER_H
