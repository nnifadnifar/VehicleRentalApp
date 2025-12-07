#ifndef IENTITY_H
#define IENTITY_H

#include <string>

class IEntity{
public:
    virtual ~IEntity() = default;
    virtual int getId() const = 0;
    virtual std::string serialize() const = 0;
    virtual void deserialize(const std::string& data) = 0;
    virtual bool isValid() const = 0;
};

#endif // IENTITY_H
