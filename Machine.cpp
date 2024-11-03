#include "Machine.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

Machine::Machine(){}

void Machine::loadProgramFile(const string& filename,int address) {

    if(address != 16){
        cpu.set_pc(address);
    }

    ifstream file(filename);
    string instruct;
    while (getline(file, instruct) && address <=255) {
            if(instruct.size()<2){
                continue ;
            }
            mem.set_value(address++, instruct.substr(0,2));
            if(address > 255){
                break ;
            }
            mem.set_value(address++, instruct.substr(2));
    }

   if(address <= 254 && mem.get_value(address - 1) != "C0" && mem.get_value(address) != "00"){
        mem.set_value(address++, "C0");
        mem.set_value(address++, "00");
    }

    file.close();
}

void Machine::loadInstructions(const string& Instructions,int address = 16) {

    if(address != 16){
        cpu.set_pc(address);
    }

    stringstream ss(Instructions);
    string instruct;

    while ((ss >> instruct) && (address <=255)) {
            if(instruct.size()<2){
                continue ;
            }
            mem.set_value(address++, instruct.substr(0,2));
            if(address > 255){
                break ;
            }
            mem.set_value(address++, instruct.substr(2));
    }

    if(address <= 254 && mem.get_value(address - 1) != "C0" && mem.get_value(address) != "00"){
        mem.set_value(address++, "C0");
        mem.set_value(address++, "00");
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
