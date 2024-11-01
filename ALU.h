#ifndef ALU_h
#define ALU_h
#include <bits/stdc++.h>
#include <bitset>

using namespace std;

class ALU {
public:
    ALU();
    vector<string> registers;       // OK
    string binToHex(string s);      // OK
    string floatToBin(float f);     //
    float hexToFloat(string s);     // OK
    int hexToDec(string s);         // OK
    string decToHex(int dec);       // OK
    string twosComp(int r1, int r2, int r3);
    string add(int r1, int r2, int r3);   ////////FUCK/////////
};

#endif //ALU_h
