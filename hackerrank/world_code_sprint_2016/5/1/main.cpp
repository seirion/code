// https://www.hackerrank.com/contests/world-codesprint-5/challenges/camelcase
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int r = 0;
    for (auto s : str) {
        if ('A' <= s && s <= 'Z') r++;
    }
    cout << r + 1 << endl;
    return 0;
}

