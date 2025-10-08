#include "Logger.hpp"
#include <fstream>
#include <iostream>
#include <ctime>

std::string Logger::outputFile = "system_log.txt";
bool Logger::verbose = false;

void Logger::setOutputFile(const std::string& filename) {
    outputFile = filename;
}

void Logger::setVerbose(bool enabled) {
    verbose = enabled;
}

void Logger::log(const std::string& message) {
    std::ofstream file(outputFile, std::ios::app);
    std::time_t now = std::time(nullptr);
    std::string timestamped = std::string(std::ctime(&now)) + ": " + message + "\n";
    file << timestamped;
    file.flush();

    if (verbose) {
        std::cout << timestamped;
    }
}