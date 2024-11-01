#include "Register.h"
#include <iostream>
using namespace std;

Register::Register(int sz) : register_size(sz), register_data(sz, "00") {}

void Register::set_value(int address, const string& value) {
    if (address < 0 || address >= register_size) {
        cout << "Inaccessible address" << endl;
    } else {
        register_data[address] = value;
    }
}

string Register::get_value(int address) {
    if (address < 0 || address >= register_size) {
        return "Inaccessible address";
    } else {
        return register_data[address];
    }
}

void Register::clear() {
    for (int i = 0; i < register_size; i++) {
        register_data[i] = "00";
    }
}
