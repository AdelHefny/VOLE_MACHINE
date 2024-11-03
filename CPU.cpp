#include "CPU.h"
#include <cmath>
#include <cctype>

using namespace std;

void CPU::fetch(Memory& mem) {
    ir = mem.getCell(pc);
    ir += mem.getCell(pc + 1);
}

int hexToInt(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else {
        return tolower(hex) - 'a' + 10;
    }
}

vector<int> CPU::decode() {
    vector<int> decoded;
    for (int i = 0; i < ir.size(); ++i) {
        decoded.push_back(hexToInt(ir[i]));
    }
    return decoded;
}
bool CPU::IsValid(const string& instruction){
    string hex_char = "0123456789ABCDEF" ;
    if(s.size() != 4){
        return false ;
    }
    for(char c : s){
        if(hex_char.find(c) == string::npos){
            return false ;
        }
    }
    return true ;
}
void CPU::runNextInstruction(Memory& mem) {
    fetch(Memory& mem);
    pc += 2;
    if(IsValid(ir)){
    vector<int> decoded_instructions = decode();
    execute(decoded_instructions);
    }
}
void CPU::reset(){
    pc = 0 ;
    ir = "" ;
    reg.reset();
    cu.reset();
}
void CPU::execute(const vector<int>& decoded) {
    int opcode = decoded[0];
    int r = decoded[1], x = decoded[2], y = decoded[3];
    int address = x * 16 + y;
    string hex_char = "0123456789ABCDEF";
    string val = "";

    val += hex_char[x];
    val += hex_char[y];

    switch (opcode) {
        case 1:
            cu.load(r, address, reg, mem);
            break;
        case 2:
            cu.load(r, val, reg);
            break;
        case 3: {
            cu.store(r, address, reg, mem);
            if (x == 0 && y == 0) {
                cout << mem.get_value(address) << '\n';
            }
            break;
        }
        case 4:
            cu.mov(y, x, reg);
            break;
        case 5:
            alu.twosComp(r, x, y, reg);
            break;
        case 6:
            alu.add(r, x, y, reg);
            break;
        case 11:
            cu.jump(r, address, reg, pc);
            break;
        case 12:
            cu.halt();
            break;
    }
}
