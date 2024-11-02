#include "Register.h"
#include <iostream>

using namespace std;

Register::Register() : register_data(REGISTER_SIZE, "00") {}

void Register::set_value(int address, const string& value) {
    if (address < 0 || address >= REGISTER_SIZE) {
        cout << "Inaccessible address" << endl;
    } else {
        register_data[address] = value;
    }
}

string Register::get_value(int address) {
    if (address < 0 || address >= REGISTER_SIZE) {
        return "Inaccessible address";
    } else {
        return register_data[address];
    }
}

void Register::reset() {
    for (int i = 0; i < REGISTER_SIZE; i++) {
        register_data[i] = "00";
    }
}
