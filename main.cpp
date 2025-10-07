#include "Logger.hpp"
#include "Monitor.hpp"
#include <thread>
#include <chrono>

void monitorLoop() {
    while (true) {
        Logger::log(getCPUUsage());
        Logger::log(getMemoryUsage());
        Logger::log(getUptime());
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}

int main() {
    std::thread monitorThread(monitorLoop);
    monitorThread.join();
    return 0;
}