#include "memory.h"
#include <iostream>
using namespace std;

void Memory::set_value(int address, const int& value) {
    if (address < 0 || address >= size) {
        cout << "inaccessible address" << endl;
    } else {
        storage[address] = value;
    }
}

int Memory::get_value(int address) {
    if (address < 0 || address >= size) {
        cout << "inaccessible address" << endl;
        return -1;
    } else {
        return storage[address];
    }
}

void Memory::clear() {
    for (int i = 0; i < size; i++) {
        storage[i] = 0;
    }
}
