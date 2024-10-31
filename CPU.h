#ifndef VOLE_MACHINE_CPU_H
#define VOLE_MACHINE_CPU_H
#include "memory.h"
#include "register.h"
#include "ALU.h"
#include "ControlUnit.h"
class CPU {
private:
    int pc;
    string ir;
    Register Reg;
    ALU alu;
    CU cu;
public:
    CPU(): pc(0), ir(""), Reg(16) {}
    void runNextStep(Memory& mem);
    void fetch(Memory& mem);
    vector<int> decode();
    void execute(Register &reg,Memory& mem,vector<int> instrction);
};


#endif
