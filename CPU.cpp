#include "CPU.h"

void CPU::fetch(memory &mem) {
    ir = mem.getCell(pc);
    ir += mem.getCell(pc+1);
}

int hexToInt(string hex){
    int num = 0;
    int p = hex.size() - 1;
    for (char c:hex) {
        if(c >= '0' && c <= '9'){
            num += (c - '0')*pow(16,p);
        }else{
            num += (tolower(c) - 'a' + 10)*pow(16,p);
        }
        p--;
    }
    return num;
}

vector<int> CPU::decode() {
    vector<int> decoded;
    if(ir[0] >= '0' && ir[0] <= '9'){
        decoded.push_back(ir[0] - '0');
    }else{
        decoded.push_back(tolower(ir[0]) - 'a' + 10);
    }
    decoded.push_back(hexToInt(to_string(ir[1])));
    decoded.push_back(hexToInt(to_string(ir[2])));
    decoded.push_back(hexToInt(to_string(ir[3])));
    return decoded;
}

void CPU::runNextStep(memory &mem) {
    pc += 2;
    fetch(mem);
    execute(Reg,mem,decode());
}