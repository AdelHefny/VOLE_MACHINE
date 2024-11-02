#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <string>

class Memory {
private:
    static const int MEMORY_SIZE = 256;
    std::vector<std::string> memory_data;

public:
    Memory();
    void set_value(int address, const std::string& value);
    std::string get_value(int address);
    void reset();
};

#endif
