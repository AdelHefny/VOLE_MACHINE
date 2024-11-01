#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <string>
using namespace std;

class Memory {
private:
    vector<string> memory_data;
    int memory_size;

public:
    Memory(int sz);
    void set_value(int address, const string& value);
    string get_value(int address);
    void clear();
};

#endif
