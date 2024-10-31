#ifndef VOLE_MACHINE_MAINUI_H
#define VOLE_MACHINE_MAINUI_H
#include "machine.h"

class MainUi {
private:
    Machine machine;
    bool enterFileOrInstruction;
public:
    MainUi(): enterFileOrInstruction(false){};
    bool getFileOrInstruction();
    void displayMenu();
    string inputFileName();
    string inputInstruction();
    int inputChoice();
};


#endif //VOLE_MACHINE_MAINUI_H
