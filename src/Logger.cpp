#include "Logger.hpp"
#include <fstream>
#include <ctime>

void Logger::log(const std::string& message) {
    std::ofstream file("system_log.txt", std::ios::app);
    std::time_t now = std::time(nullptr);
    file << std::ctime(&now) << ": " << message << "\n";
}