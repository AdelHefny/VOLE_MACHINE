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
    CPU(Register* reg, ALU* alu, CU* cu)
            : pc(0), ir(""), Reg(reg), alu(alu), cu(cu) {}
    void runNextStep(memory& mem);
    void fetch(memory& mem);
    vector<int> decode();
    void execute(Register &reg,memory& mem,vector<int> instrction);
};


#endif
