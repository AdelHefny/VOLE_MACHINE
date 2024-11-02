#include "Memory.h"
#include <iostream>

using namespace std;

Memory::Memory() : memory_data(MEMORY_SIZE, "00") {}

void Memory::set_value(int address, const std::string& value) {
    if (address < 0 || address >= MEMORY_SIZE) {
        cout << "Inaccessible address" << endl;
    } else {
        memory_data[address] = value;
    }
}

std::string Memory::get_value(int address) {
    if (address < 0 || address >= MEMORY_SIZE) {
        return "Inaccessible address";
    } else {
        return memory_data[address];
    }
}

void Memory::reset() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory_data[i] = "00";
    }
}
