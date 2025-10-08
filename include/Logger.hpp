#pragma once
#include <string>

class Logger {
public:
    static void log(const std::string& message);
    static void setOutputFile(const std::string& filename);

private:
    static std::string outputFile;
};