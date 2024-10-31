#ifndef ALU_h
#define ALU_h
#include <bits/stdc++.h>
#include <bitset>
#include "register.h"
using namespace std;

class ALU {
public:
    ALU() {};
    string binToHex(string s);
    string decToBin(int dec);
    string floatToBin(float f);
    float binToFloat(string s);
    int hexToDec(string s);
    string decToHex(int dec);
   void add(int r1, int r2, int r3,Register& registers);
};

#endif //ALU_h
