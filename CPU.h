    #ifndef VOLE_MACHINE_CPU_H
#define VOLE_MACHINE_CPU_H

#include "Memory.h"
#include "Register.h"
#include "ALU.h"
#include "ControlUnit.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CPU {
private:
    int pc;
    string ir;
public:
    Register reg;
    CU cu;
    ALU alu;
    CPU() : pc(16), ir("") {}
    void runNextInstruction(Memory& mem);
    void fetch(Memory& mem);
    vector<int> decode();
    void execute(const vector<int>& decoded,Memory& mem);
    bool IsValid(const string& instruction);
    void reset();
    void set_pc(int initialValue);
};

#endif
