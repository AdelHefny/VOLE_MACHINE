#ifndef VOLE_MACHINE_CPU_H
#define VOLE_MACHINE_CPU_H

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
    Register reg;
    ALU alu;
    CU cu;
public:
    CPU() : pc(0), ir(""){}
    void runNextInstruction(Memory& mem);
    void fetch(Memory& mem);
    vector<int> decode();
    void execute(const vector<int>& decoded);
    bool CPU::IsValid(const string& instruction) ;
    void reset() ;
};

#endif
