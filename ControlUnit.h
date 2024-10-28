#ifndef VOLE_MACHINE_CONTROLUNIT_H
#define VOLE_MACHINE_CONTROLUNIT_H

class Register;
class Memory;

class CU {
private:
    bool haltFlag;

public:
    CU() : haltFlag(false) {}

    void load(int idxReg, int intMem, vector<Register>& reg, const Memory& mem);
    void load(int idxReg, string val, vector<Register>& reg);
    void store(string reg, string& mem);
    void mov(int reg1idx, int reg2idx, vector<Register>& reg);
    void jump(int regIdx, int memIdx, vector<Register>& reg, string& pc, const Memory& memory);
    void halt();
};
#endif
