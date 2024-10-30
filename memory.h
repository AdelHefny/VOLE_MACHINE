#ifndef STOARAGE_H
#define STOARAGE_H

#include <vector>
#include <string>
using namespace std;

class memory {
private:
    vector<string> storage;
    int size = 256;

public:
    memory(int sz);
    void set_value(int address, const string& value);
    string get_value(int address);
    void clear();
};

#endif // STOARAGE_H
