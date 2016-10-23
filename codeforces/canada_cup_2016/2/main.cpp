#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

long long order(char col) {
    switch (col) {
        case 'f': return 1;
        case 'e': return 2;
        case 'd': return 3;
        case 'a': return 4;
        case 'b': return 5;
        case 'c': return 6;
    }
    return -1;
}

long long calc(long long row, char col) {
    long long r = 0;

    r += (row / 4LL) * 16LL;
    row = row % 4LL;

    if (2 <= row) row -= 2;
    r += row * 7;

    r += order(col);
    return r;
}

int main() {
    string s; cin >> s;
    long long row = atoll(s.c_str());
    
    int size = s.size();
    cout << calc(row-1, s[size-1]) << endl;
    return 0;
}
