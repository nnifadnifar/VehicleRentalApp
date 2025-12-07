#ifndef ICONTROLLER_H
#define ICONTROLLER_H
#include <vector>

template<typename T>
class IController {
public:
    virtual std::vector<T> getAll() const = 0;
    virtual T* getById(int id) = 0;
    virtual bool add(const T& item) = 0;
    virtual bool update(const T& item) = 0;
    virtual bool remove(int id) = 0;
    virtual bool saveToFile() = 0;
    virtual bool loadFromFile() = 0;
    virtual int getCount() const = 0;
};

#endif // ICONTROLLER_H
