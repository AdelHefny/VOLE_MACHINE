#include "ALU.h"
#include <bits/stdc++.h>

using namespace std;

ALU::ALU() {}

float ALU::hexToFloat(string hex) {
    int x = hexToDec(hex);
    bitset<8> bs(x);
    string bin = bs.to_string();
    int sign = bin[0] - '0', bias = 4;
    int exponent = bitset<3>(bin.substr(1, 3)).to_ulong();
    int mantissa = bitset<4>(bin.substr(4, 4)).to_ulong();
    float ex = exponent - bias, mantissaVal = 0.0;

    for (int i = 0; i < 4; i++) {
        if (mantissa & (1 << (3 - i))) {
            mantissaVal += pow(2, -(i + 1));
        }
    }

    float res = pow(-1, sign) * mantissaVal * pow(2, ex);
    return res;
}

int ALU::hexToDec(string s) {
    return stoi(s, nullptr, 16);
}

string ALU::floatToBin(float f) {
    int sign = f < 0 ? 1 : 0;
    if (f < -7.5) f = -7.5;
    else if (f > 7.5) f = 7.5;
    f = fabs(f);

    int intPart = static_cast<int>(f);
    float frac = f - intPart;

    string fracBin = "", intBin = "", Bin = "";
    string mantissa = "";
    while (frac > 0.0 && fracBin.size() < 8) {
        frac *= 2;
        if (frac >= 1.0) {
            fracBin += "1";
            frac -= 1.0;
        } else {
            fracBin += "0";
        }
    }

    if (intPart == 0) intBin = "0";
    else {
        while (intPart > 0) {
            intBin = (intPart % 2 == 0 ? "0" : "1") + intBin;
            intPart /= 2;
        }
    }

    Bin = intBin + "." + fracBin;

    int ex = 0;
    auto it = find(Bin.begin(), Bin.end(), '.');
    if (f > 1.0) {
        ex = it - Bin.begin();
        mantissa += Bin.substr(0, ex);
        mantissa += Bin.substr(ex + 1, 4 - ex);
    } else {
        int x = it - Bin.begin(), indx = 0;
        for (int i = x + 1; i < Bin.size(); i++) {
            if (Bin[i] == '1') {
                indx = i;
                break;
            }
            --ex;
            if (ex == -4) {
                indx = i + 1;
                break;
            }
        }
        mantissa = Bin.substr(indx, 4);
    }

    while (mantissa.size() < 4) {
        mantissa += "0";
    }

    int biasedexp = ex + 4;
    return to_string(sign) + bitset<3>(biasedexp).to_string() + mantissa;
}

string ALU::decToHex(int dec) {
    stringstream ss;
    ss << hex << uppercase << dec;
    return ss.str();
}

string ALU::binToHex(string bin) {
    unsigned long binValue = bitset<8>(bin).to_ulong();
    stringstream ss;
    ss << hex << binValue;
    string hexValue = ss.str();
    for (char& c : hexValue) {
        c = toupper(c);
    }
    return hexValue;
}

void ALU::add(int idx_r1, int idx_r2, int idx_r3, Register& reg) {
    float f1 = hexToFloat(reg.get_value(idx_r1));
    float f2 = hexToFloat(reg.get_value(idx_r2));
    float ans = f1 + f2;
    string bin = floatToBin(ans);
    string hex = binToHex(bin);
    reg.set_value(idx_r3, hex);
}

void ALU::twosComp(int idx_r1, int idx_r2, int idx_r3, Register& reg) {
    int a = hexToDec(reg.get_value(idx_r1)), b = hexToDec(reg.get_value(idx_r2));
    if (a >= 0x80) a -= 256;
    if (b >= 0x80) b -= 256;

    int ans = a + b;

    if (ans < 0) ans += 256;

    string res = decToHex(ans);
    reg.set_value(idx_r3, res);
}
