#include "../headers/ICommand.h"
#include <iostream>
#include <chrono>
#include <ctime>

class TimeCommand : public ICommand {
public:
    std::string name() const override { return "time"; }

    void execute(const std::string& args) override {
        (void)args;
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        std::cout << "Current system time: " << std::ctime(&currentTime);
    }
};