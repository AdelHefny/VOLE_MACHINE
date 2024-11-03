#ifndef STOARAGE_H
#define STOARAGE_H

#include <vector>
#include <string>
using namespace std;

class Stoarage {
private:
    vector<string> storage;
    int size;

public:
    Stoarage(int sz);
    void set_value(int address, const string& value);
    int get_value(int address);
    void clear();
};

#endif
