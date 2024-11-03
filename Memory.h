#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <string>
using namespace std ;
class Memory {
private:
    static const int MEMORY_SIZE = 256;
    vector<string> memory_data;

public:
    Memory();
    void set_value(int address, const string& value);
    string get_value(int address);
    void reset();
};

#endif
