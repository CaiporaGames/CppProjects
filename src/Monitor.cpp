#include "Monitor.hpp"
#include <fstream>
#include <sstream>
#include <string>

std::string getCPUUsage() {
    return "CPU: simulated 42%";
}

std::string getMemoryUsage() {
    return "Memory: simulated 3.2 GB used";
}

std::string getUptime() {
    std::ifstream file("/proc/uptime");
    std::string uptime;
    std::getline(file, uptime);
    return "Uptime: " + uptime;
}