#include "register.h"
#include <iostream>
using namespace std;

void Register::set_value(int address, const int& value) {
    if (address < 0 || address >= size) {
        cout << "inaccessible address" << endl;
    } else {
        storage[address] = value;
    }
}

int Register::get_value(int address) {
    if (address < 0 || address >= size) {
        throw "inaccessible address";
    } else {
        return storage[address];
    }
}

void Register::clear() {
    for (int i = 0; i < size; i++) {
        storage[i] = 0;
    }
}
