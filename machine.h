#ifndef VOLE_MACHINE_MACHINE_H
#define VOLE_MACHINE_MACHINE_H
#include "CPU.h"
#include "memory.h"

class Machine {
private:
    CPU cpu;
    Memory mem;
public:
    Machine(): mem(256){};
    void loadProgramFile();
    void outputState();
};


#endif
