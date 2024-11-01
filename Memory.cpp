#include "Memory.h"
#include <iostream>
using namespace std;

Memory::Memory(int sz) : memory_size(sz), memory_data(sz, "00") {}

void Memory::set_value(int address, const string& value) {
    if (address < 0 || address >= memory_size) {
        cout << "Inaccessible address" << endl;
    } else {
        memory_data[address] = value;
    }
}

string Memory::get_value(int address) {
    if (address < 0 || address >= memory_size) {
        return "Inaccessible address";
    } else {
        return memory_data[address];
    }
}

void Memory::clear() {
    for (int i = 0; i < memory_size; i++) {
        memory_data[i] = "00";
    }
}
