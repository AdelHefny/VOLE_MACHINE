#ifndef STOARAGE_H
#define STOARAGE_H

#include <vector>
#include <string>
using namespace std;

class Memory {
private:
    vector<int> storage;
    int size = 256;

public:
    Memory(int sz): size(sz),storage(sz){};
    void set_value(int address, const int& value);
    int get_value(int address);
    void clear();
};

#endif // STOARAGE_H
