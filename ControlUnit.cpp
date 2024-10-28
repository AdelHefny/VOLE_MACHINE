#include "ControlUnit.h"
#include <bits/stdc++.h>
#include <bitset>

using namespace std;

// Definitions of CU methods

void CU::load(int idxReg, int intMem, vector<Register>& reg, const Memory& mem) {
    reg[idxReg].setData(mem.getData(intMem));
}

void CU::load(int idxReg, string val, vector<Register>& reg) {
    reg[idxReg].setData(val);
}

void CU::store(string reg, string& mem) {
    mem = reg;
}

void CU::mov(int reg1idx, int reg2idx, vector<Register>& reg) {
    reg[reg1idx] = reg[reg2idx];
}

void CU::jump(int regIdx, int memIdx, vector<Register>& reg, string& pc, const Memory& memory) {
    if (reg[regIdx].getData() != 0) {
        pc = memory.getData(memIdx);
    }
}

void CU::halt() {
    haltFlag = true;
}
