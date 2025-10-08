#pragma once
#include <string>
#include <mutex>

class Logger {
public:
    static void setOutputFile(const std::string& filename);
    static void setVerbose(bool enabled);
    static void log(const std::string& message);
private:
    static std::string outputFile;
    static bool verbose;
    static std::mutex logMutex;
};