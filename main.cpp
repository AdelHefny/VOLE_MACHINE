#include "ALU.h"
#include <bits/stdc++.h>
#include <bitset>

using namespace std;
int hexToInt(string hex){
    int num = 0;
    int p = hex.size() - 1;
    for (char c:hex) {
        if(c >= '0' && c <= '9'){
            num += (c - '0')*pow(16,p);
        }else{
            num += (tolower(c) - 'a' + 10)*pow(16,p);
        }
        p--;
    }
    return num;
}
int main() {
    string s;cin >> s;
    cout << hexToInt(s) << endl;
    return 0;
}
