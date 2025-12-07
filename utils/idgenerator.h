#ifndef IDGENERATOR_H
#define IDGENERATOR_H


#include <unordered_map>
#include <string>

class IdGenerator {
private:
    std::unordered_map<std::string, int> m_counters;  ///< Counters per entity type
    IdGenerator() = default;

public:
    IdGenerator(const IdGenerator&) = delete;
    IdGenerator& operator=(const IdGenerator&) = delete;
    static IdGenerator& getInstance();
    int getNextId(const std::string& entityType);
    void updateCounter(const std::string& entityType, int id);
    int getCurrentCounter(const std::string& entityType) const;
    void resetCounter(const std::string& entityType);
    void resetAll();
};

#endif // IDGENERATOR_H
