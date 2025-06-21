#pragma once

#include "ICommand.h"
#include <chrono>
#include <string>

class SessionTimeCommand : public ICommand {
public:
    SessionTimeCommand(std::chrono::time_point<std::chrono::steady_clock> start);
    std::string name() const override;
    void execute(const std::string& args) override;

private:
    std::chrono::time_point<std::chrono::steady_clock> sessionStart;
};