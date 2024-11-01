#ifndef ALU_H
#define ALU_H

#include <bits/stdc++.h>
#include "Register.h"

using namespace std;

class ALU {
public:
    ALU();
    string binToHex(string s);      // OK
    string floatToBin(float f);     // OK
    float hexToFloat(string s);     // OK
    int hexToDec(string s);         // OK
    string decToHex(int dec);       // OK
    void twosComp(int idx_r1, int idx_r2, int idx_r3, Register& reg);
    void add(int idx_r1, int idx_r2, int idx_r3, Register& reg);
};

#endif // ALU_H
