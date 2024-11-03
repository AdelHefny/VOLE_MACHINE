#ifndef MACHINE_H
#define MACHINE_H

#include "CPU.h"
#include "Memory.h"
#include <string>
#include <iomanip>
#include <sstream>

using namespace std ;
class Machine {
private:
    CPU cpu;
    Memory mem;
public:
    Machine();
    void loadProgramFile(const string& filename,int address = 16);
    void runProgram();
    void outputState() ;
    void reset();
    void loadInstructions(const string& Instructions,int address) ;
};

#endif
