#include "MainUi.h"

bool MainUi::getFileOrInstruction() {
    return enterFileOrInstruction;
}

string MainUi::inputFileName() {
    string fileName;
    cout << "Enter the file name: ";
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
            cout << "Invalid instruction: Cxxx format required for halt operation." << endl;
            return "-1";
        }
        return inst;
    } else {
        cout << "Invalid instruction: first character must be 1-9 or A-D." << endl;
        return "-1";
    }
}

int MainUi::inputChoice() {
    char choice;
    cin >> choice;
    choice = tolower(choice);
    if(choice > 'c' || choice < 'a'){
        return -1;
    }
    return choice - 'a';
}

void MainUi::displayMenu() {
    cout << "Menu\n1)Input File\n2)Input Instruction\n3)Exit" << endl;
}