#ifndef register_H
#define register_H

#include <vector>
#include <string>
using namespace std;

class Register {
private:
    vector<int> storage;
    int size = 16;
public:
    Register(int sz) : size(sz), storage(sz, 0) {};
    void set_value(int address, const int& value);
    int get_value(int address);
    void clear();
};

#endif // register_H
