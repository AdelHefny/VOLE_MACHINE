#ifndef REGISTER_H
#define REGISTER_H

#include <vector>
#include <string>
using namespace std;

class Register {
private:
    vector<string> register_data;
    int register_size;

public:
    Register(int sz);
    void set_value(int address, const string& value);
    string get_value(int address);
    void clear();
};

#endif
