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
    Memory mem;
    ALU alu;
    CU cu;
public:
    CPU() : pc(0), ir(""), reg(16), mem(256) {}
    void run();
    void fetch();
    vector<int> decode();
    void execute(const vector<int>& decoded);
};

#endif
