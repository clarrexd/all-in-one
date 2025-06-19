#pragma once
#include "ICommand.h"
#include <string>

class LineCountCommand : public ICommand {
public:
    std::string name() const override;
    void execute(const std::string& args) override;
};