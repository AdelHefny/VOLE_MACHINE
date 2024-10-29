#include "ALU.h"
#include <bits/stdc++.h>
#include <bitset>

using namespace std;

int main() {
    ALU alu;

    alu.registers[0] = "1A";
    alu.registers[1] = "0F";
    alu.registers[2] = "00";

    cout << "Initial values in registers:" << endl;
    cout << "registers[0] (1A): " << alu.hexToDec(alu.registers[0]) << endl; // Should print 26
    cout << "registers[1] (0F): " << alu.hexToDec(alu.registers[1]) << endl; // Should print 15

    // Perform addition of the values in registers 0 and 1, store the result in register 2
    alu.add(0, 1, 2);  // This adds the values in registers[0] and registers[1] and stores the result in registers[2]

    // Print the result in register 2
    cout << "Result in registers[2]: " << alu.registers[2] << endl; // Expect to see the hex representation of 41 (26 + 15)

    // Additional tests for other functions
    string testBin = "01010101"; // Example binary
    cout << "Binary to Float: " << alu.binToFloat(testBin) << endl; // Test binToFloat with 01010101

    int testDec = 41; // Decimal for testing decToHex
    cout << "Decimal to Hex: " << alu.decToHex(testDec) << endl; // Should print "29"

    string testHex = "29";
    cout << "Hex to Decimal: " << alu.hexToDec(testHex) << endl; // Should print "41"

    string testBin2 = "101111"; // Example binary
    cout << "Binary to Hex: " << alu.binToHex(testBin2) << endl; // Should print "2F"
    return 0;
}
