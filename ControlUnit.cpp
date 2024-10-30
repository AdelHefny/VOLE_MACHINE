#include "ControlUnit.h"
#include <bits/stdc++.h>
#include <bitset>

using namespace std;

void CU::load(int idxReg, int intMem, Register reg, const Memory& mem) {
    reg.setData(idxReg,mem.getData(intMem));
}

void CU::load(int idxReg, string val, Register reg) {
    reg.setData(idxReg,val);
}

void CU::store(string reg, string& mem) {
    mem = reg;
}

void CU::mov(int reg1idx, int reg2idx, vector<Register>& reg) {
    reg[reg1idx] = reg[reg2idx];
}

void CU::jump(int regIdx, int memIdx, Register& reg, string& pc, const Memory& memory) {
    if (reg.getData(regIdx) == reg.getData(0)) {
        pc = memIdx;
    }
}

void CU::halt() {
    haltFlag = true;
}
