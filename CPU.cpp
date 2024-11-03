#include "CPU.h"
#include <cmath>
#include <cctype>

using namespace std;

void CPU::fetch() {
    ir = mem.get_value(pc);
    ir += mem.get_value(pc + 1);
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

void CPU::run() {
    while (true) {
        fetch();
        pc += 2;
        vector<int> decoded_instructions = decode();
        execute(decoded_instructions);
        if (cu.get_flag()) {
            break;
        }
    }
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
            alu.add(r, x, y, reg);
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
