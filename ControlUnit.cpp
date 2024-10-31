#include "ControlUnit.h"
#include "Register.h"
#include "Memory.h"
#include <string>
#include <iostream>

using namespace std;

void CU::load(int idxReg, int intMem, Register& reg, Memory& mem) {
    int data = mem.get_value(intMem);
    reg.set_value(idxReg, data);
}

void CU::load(int idxReg, const int& val, Register& reg) {
    reg.set_value(idxReg, val);
}

void CU::store(const string& regData, string& mem) {
    mem = regData;
}

void CU::mov(int reg1idx, int reg2idx, Register& reg) {
    int data = reg.get_value(reg2idx);
    reg.set_value(reg1idx, data);
}

void CU::jump(int regIdx, int memIdx, Register& reg, int& pc,Memory& memory) {
    if (reg.get_value(regIdx) == reg.get_value(0)) {
        pc = memIdx;
    }
}

void CU::halt() {
    haltFlag = true;
}