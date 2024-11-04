#ifndef ALU_H
#define ALU_H

#include <bits/stdc++.h>
#include "Register.h"

using namespace std;

class ALU {
public:
    ALU();
    string binToHex(string s);
    string floatToBin(float f);
    float hexToFloat(string s);
    int hexToDec(string s);
    string decToHex(int dec);
    void twosComp(int idx_r1, int idx_r2, int idx_r3, Register& reg);
    void add(int idx_r1, int idx_r2, int idx_r3, Register& reg);
    void bitwiseOr(int idx_r1, int idx_r2, int idx_r3, Register& reg);
    void bitwiseAnd(int idx_r1, int idx_r2, int idx_r3, Register& reg);
    void bitwiseXor(int idx_r1, int idx_r2, int idx_r3, Register& reg);
    void rotateRight(int idx_r1, int idx_r2, int steps, Register& reg);
};

#endif // ALU_H
