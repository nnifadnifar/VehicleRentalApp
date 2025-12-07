#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <string>
#include <vector>

class DataHandler{
private:
    std::string m_dataPath;

public:
    explicit DataHandler(const std::string& dataPath = "data/");
    std::string getDataPath()const;
    void setDataPath(const std::string& path);
    std::vector<std::string> readLines(const std::string& filename) const;
    bool writeLines(const std::string& filename, const std::vector<std::string>& lines) const;
    bool appendLine(const std::string& filename, const std::string& line) const;
    bool fileExists(const std::string& filename) const;
    bool ensureFileExists(const std::string& filename) const;
    static std::vector<std::string> splitLine(const std::string& line, char delimiter = '|');
    static std::string joinFields(const std::vector<std::string>& fields, char delimiter = '|');
    static std::string trim(const std::string& str);
};

#endif // DATAHANDLER_H
