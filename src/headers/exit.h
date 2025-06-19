#pragma once

#include "ICommand.h"
#include <functional>
#include <string>

class ExitCommand : public ICommand {
public:
    explicit ExitCommand(std::function<void()> callback);
    std::string name() const override;
    void execute(const std::string& args) override;

private:
    std::function<void()> onExit;
};