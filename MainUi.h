#ifndef VOLE_MACHINE_MAINUI_H
#define VOLE_MACHINE_MAINUI_H

#include "machine.h"
#include <string>

class MainUi {
public:
    bool enterFileOrInstruction;
    Machine machine;
    MainUi() : enterFileOrInstruction(false) {}

    bool getFileOrInstruction();
    void displayMenu();
    std::string inputFileName();
    std::string inputInstruction();
    int inputChoice();
};

#endif // VOLE_MACHINE_MAINUI_H
