#include "storage.h"
#include <iostream>
using namespace std;

Stoarage::Stoarage(int sz) : size(sz), storage(size, "00") {}

void Stoarage::set_value(int address, const string& value) {
    if (address < 0 || address >= size) {
        cout << "inaccessible address" << endl;
    } else {
        storage[address] = value;
    }
}

string Stoarage::get_value(int address) {
    if (address < 0 || address >= size) {
        return "inaccessible address";
    } else {
        return storage[address];
    }
}

void Stoarage::clear() {
    for (int i = 0; i < size; i++) {
        storage[i] = "00";
    }
}
