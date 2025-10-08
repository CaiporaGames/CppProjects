#include "Logger.hpp"
#include <fstream>
#include <ctime>

std::string Logger::outputFile = "system_log.txt";

void Logger::setOutputFile(const std::string& filename)
{
    outputFile = filename;
}

void Logger::log(const std::string& message) 
{
    std::ofstream file(outputFile, std::ios::app);
    std::time_t now = std::time(nullptr);
    file << std::ctime(&now) << ": " << message << "\n";
}