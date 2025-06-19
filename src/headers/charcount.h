#pragma once

#include "ICommand.h"
#include <string>

class CharCountCommand : public ICommand {
public:
    std::string name() const override { return "charcount"; }
    void execute(const std::string& args) override;
};