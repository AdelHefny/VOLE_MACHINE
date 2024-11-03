#include <bits/stdc++.h>
#include "MainUi.h"
using namespace std;

int main() {
    MainUi ui;
    while(true){
        ui.displayMenu();
        int choice = ui.inputChoice();
        if(choice == 0) {
            ui.machine.loadProgramFile(ui.inputFileName());
        }else if(choice == 1){
            ui.enterFileOrInstruction = true;
            ui.inputInstruction();
        }else if(choice == 2){
            break;
        }
    }
    return 0;
}
