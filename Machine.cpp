#include "Machine.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

Machine::Machine(){}

void Machine::loadProgramFile(const string& filename,int address = 10) {
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
            mem.set_value(address++, line);
            if(address > 255|| address <0){
                break ;
            }
    }

    if(mem.get_value(address) != "C000" && address <= 255){
        mem.set_value(address++, "C000");
    }

    file.close();
}

void Machine::loadInstructions(const string& Instructions,int address = 10) {
    stringstream ss(Instructions);
    string instruct;

    while (ss >> instruct) {
            mem.set_value(address++, instruct);
            if(address > 255 || address < 0){
                break ;
            }
    }

    if(mem.get_value(address) != "C000" && address <= 255){
        mem.set_value(address++, "C000");
    }

}

void Machine::runProgram() {
    while (!cpu.cu.IsHalted()) {
        cpu.runNextInstruction(mem);
    }
}

void Machine::reset(){
    cpu.reset();
    mem.reset() ;
}


void Machine::outputState(){
    cout << "==============================" << '\n';
    cout << "          Register State      " << '\n';
    cout << "==============================" << '\n';
    cout << setw(15) << "Register no" << setw(15) << "Value" << '\n';
    cout << "------------------------------" << '\n';
    for (int i = 0; i < 16; ++i) {
        cout << setw(15) << "Register[" << i << "]"
             << setw(15) << cpu.reg.get_value(i) << '\n';
    }

    cout << "\n==============================" << '\n';
    cout << "          Memory State        " << '\n';
    cout << "==============================" << '\n';
    cout << setw(15) << "Cell no" << setw(15) << "Value" << '\n';
    cout << "------------------------------" << '\n';
    for (int i = 0; i < 256; ++i) {
        cout << setw(15) << "Cell[" << i << "]"
             << setw(15) << mem.get_value(i) << '\n';
    }
    cout << "==============================" << '\n';
}
