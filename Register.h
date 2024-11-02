#ifndef REGISTER_H
#define REGISTER_H

#include <vector>
#include <string>
using namespace std ;
class Register {
private:
    static const int REGISTER_SIZE = 16;
    vector<string> register_data;

public:
    Register();
    void set_value(int address, const string& value);
    string get_value(int address);
    void reset();
};

#endif
