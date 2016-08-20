// http://codeforces.com/contest/707/problem/A
#include <iostream>
#include <string>

using namespace std;

int row, col;
int main() {
    cin >> row >> col;
    int size = row * col;
    while (size--) {
        string s; cin >> s;
        char c = s[0];
        if (c == 'C' || c == 'M' || c == 'Y') {
            cout << "#Color\n";
            return 0;
        }
    }
    cout << "#Black&White\n";
    return 0;
}
