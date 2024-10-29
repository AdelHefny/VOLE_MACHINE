#include "ALU.h"
#include <bits/stdc++.h>
#include <bitset>

using namespace std;

float ALU::binToFloat(string bin) {
    int sign = bin[0] - '0', bias = 4;
    int exponent = bitset<3>(bin.substr(1, 3)).to_ulong();
    int mantissa = bitset<4>(bin.substr(4, 4)).to_ulong();
    float ex = exponent - bias, mantissaVal = 0.0;

    for(int i = 0; i < 4; i++){
        if (mantissa & (1 << (3 - i))) {
            mantissaVal += pow(2, -(i + 1));
        }
    }

    float res = pow(-1, sign) * mantissaVal * pow(2, ex);
    return res;
}

string ALU::decToBin(int dec) {
    string bin = "";
    while(dec > 0){
        bin = to_string(dec%2) + bin;
        dec /= 2;
    }
    while (bin.length() < 8) {
        bin.insert(0, "0");
    }
    return (bin.size() > 0? bin : "00000000");
}

int ALU::hexToDec(string s) {
    return stoi(s, nullptr, 16);
}

string ALU::floatToBin(float f) {
    int sign = f < 0 ? 1 : 0;
    f = fabs(f);

    int exponent = 0;
    while (f >= 1.0 && exponent < 4) {
        f /= 2.0, exponent++;
    }
    while (f < 0.5 && exponent > -4) {
        f *= 2.0, exponent--;
    }

    int biasedExponent = exponent + 4, mantissa = 0;
    for (int i = 0; i < 4; ++i) {
        f *= 2.0;
        if (f >= 1.0) {
            mantissa |= (1 << (3 - i));
            f -= 1.0;
        }
    }

    string bin = to_string(sign) + bitset<3>(biasedExponent).to_string() + bitset<4>(mantissa).to_string();
    return bin;
}

string ALU::decToHex(int dec) {
    stringstream ss;
    ss << hex << uppercase << dec;
    return ss.str();
}

string ALU::binToHex(string s) {
    int x = stoi(s, nullptr, 2);
    string hex = decToHex(x);
    return hex;
}

void ALU::add(int r1, int r2, int r3) {
    string bin1 = decToBin(hexToDec(registers[r1]));
    string bin2 = decToBin(hexToDec(registers[r2]));

    float f1 = binToFloat(bin1), f2 = binToFloat(bin2);

    float ans = f1 + f2;

    if (ans < -7.5) ans = -7.5;
    else if (ans > 7.5) ans = 7.5;

    string bin = floatToBin(ans);
    string hex = binToHex(bin);
}
