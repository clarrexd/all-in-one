#include "../headers/cwd.h"
#include <iostream>
#include <unistd.h>
#include <limits.h>

std::string CwdCommand::name() const {
    return "cwd";
}

void CwdCommand::execute(const std::string& args) {
    (void)args;

    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        std::cout << "Current working directory: " << cwd << "\n";
    } else {
        perror("getcwd() error");
    }
}