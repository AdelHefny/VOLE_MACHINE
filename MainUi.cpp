#include <iostream>
#include <fstream>
#include "MainUi.h"
using namespace std;

bool MainUi::getFileOrInstruction() {
    return enterFileOrInstruction;
}

string MainUi::inputFileName() {
    string fileName;
    cout << "Enter the file name:";
    cin >> fileName;

    ifstream file(fileName);
    if (!file) {
        cerr << "Error: File does not exist or cannot be opened." << endl;
        return "";
    }
    return fileName;
}

string MainUi::inputInstruction() {
    string inst;
    cout << "Enter the instruction: ";
    cin >> inst;

    if (inst.size() != 4) {
        cout << "Invalid instruction: must be 4 characters long." << endl;
        return "-1";
    }

    char firstChar = toupper(inst[0]);

    if ((firstChar >= '1' && firstChar <= '9') || (firstChar >= 'A' && firstChar <= 'D')) {
        if (firstChar == 'C' && inst.substr(1) != "xxx") {
            cout << "Invalid instruction: 'C' instructions must be in 'Cxxx' format for halt operation." << endl;
            return "-1";
        }
        return inst;
    } else {
        cout << "Invalid instruction: first character must be between 1-9 or A-D." << endl;
        return "-1";
    }
}

int MainUi::inputChoice() {
    machine.reset();
    char choice;
    cout << "Enter your choice (a, b, or c):";
    cin >> choice;
    choice = tolower(choice);

    if (choice < 'a' || choice > 'c') {
        cout << "Invalid choice. Please enter a, b, or c." << endl;
        return -1;
    }

    return choice - 'a';
}

void MainUi::displayMenu() {
    cout << "Menu\n a) Input File\n b) Input Instruction\n c) Exit" << endl;
}