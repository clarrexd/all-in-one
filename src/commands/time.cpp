#include "../headers/time.h"
#include <iostream>
#include <chrono>
#include <ctime>

std::string TimeCommand::name() const {
    return "time";
}

void TimeCommand::execute(const std::string& args) {
    (void)args;
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::cout << "Current system time: " << std::ctime(&currentTime);
}