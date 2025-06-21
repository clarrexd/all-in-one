#include "../headers/sessiontime.h"
#include <iostream>

SessionTimeCommand::SessionTimeCommand(std::chrono::time_point<std::chrono::steady_clock> start)
    : sessionStart(start) {}

std::string SessionTimeCommand::name() const {
    return "sessiontime";
}

void SessionTimeCommand::execute(const std::string& args){
    (void)args;

    auto now = std::chrono::steady_clock::now();
    auto totalSeconds = std::chrono::duration_cast<std::chrono::seconds>(now - sessionStart).count();

    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;

    std::cout << "You've been in this session for ";

    bool printed = false;
    if (hours > 0) {
        std::cout << hours << " hour" << (hours > 1 ? "s" : "");
        printed = true;
    }
    if (minutes > 0) {
        if (printed) std::cout << ", ";
        std::cout << minutes << " minute" << (minutes > 1 ? "s" : "");
        printed = true;
    }
    if (seconds > 0 || !printed) {
        if (printed) std::cout << ", ";
        std::cout << seconds << " second" << (seconds != 1 ? "s" : "");
    }

    std::cout << ".\n";
}