// https://code.google.com/codejam/contest/11254486/dashboard#s=p0
// Problem A. Getting the Digits
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

const string STR [] = {
    //"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
    "ONE", "THREE", "FIVE", "SEVEN", "NINE"
};


int main() {
    map<char, int> m;
    for (auto &str : STR) {
        for (char c: str) {
            m[c]++;
        }
    }
    
    for (auto c : m) cout << c.first << " " << c.second << endl;;
}

