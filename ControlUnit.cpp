#include "ControlUnit.h"
#include "Register.h"
#include "Memory.h"
#include <string>
#include <iostream>

using namespace std;

void CU::load(int idxReg, int memIdx, Register& reg, Memory& mem) {
    string data = mem.get_value(memIdx);
    reg.set_value(idxReg, data);
}

void CU::load(int idxReg, const string& val, Register& reg) {
    reg.set_value(idxReg, val);
}

void CU::store(int idxReg, int memIdx, Register& reg, Memory& mem) {
    string data = reg.get_value(idxReg);
    mem.set_value(memIdx, data);
}

void CU::mov(int reg1Idx, int reg2Idx, Register& reg) {
    string data = reg.get_value(reg2Idx);
    reg.set_value(reg1Idx, data);
}

void CU::jump(int regIdx, int memIdx, Register& reg, int& pc) {
    if (reg.get_value(regIdx) == reg.get_value(0)) {
        pc = memIdx;
    }
}
bool CU::get_flag(){
    return haltFlag ;
}
void CU::halt() {
    haltFlag = true;
}
