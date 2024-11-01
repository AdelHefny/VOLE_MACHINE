#ifndef VOLE_MACHINE_CONTROLUNIT_H
#define VOLE_MACHINE_CONTROLUNIT_H

#include <string>
#include "Register.h"
#include "Memory.h"

class CU {
private:
    bool haltFlag;

public:
    CU() : haltFlag(false) {}

    void load(int idxReg, int memIdx, Register& reg, Memory& mem);
    void load(int idxReg, const string& val, Register& reg);
    void store(int idxReg, int memIdx, Register& reg, Memory& mem);
    void mov(int reg1Idx, int reg2Idx, Register& reg);
    void jump(int regIdx, int memIdx, Register& reg, int& pc);
    bool get_flag() ;
    void halt();
};

#endif
