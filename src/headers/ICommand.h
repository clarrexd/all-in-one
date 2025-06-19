#pragma once
#include <string>

class ICommand {
    public:
        virtual ~ICommand() = default;
        virtual std::string name() const = 0;
        virtual void execute(const std::string& args) = 0;
};