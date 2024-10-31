#ifndef VOLE_MACHINE_CONTROLUNIT_H
#define VOLE_MACHINE_CONTROLUNIT_H

#include <string>
#include "register.h"
#include "memory.h"

class CU {
private:
    bool haltFlag;

public:
    CU() : haltFlag(false) {}

    void load(int idxReg, int intMem, Register& reg,Memory& mem);
    void load(int idxReg, const int& val, Register& reg);
    void store(const string& regData, string& mem);
    void mov(int reg1idx, int reg2idx, Register& reg);
    void jump(int regIdx, int memIdx, Register& reg, int& pc,Memory& memory);
    void halt();
};

#endif