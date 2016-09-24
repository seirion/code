// https://www.hackerrank.com/contests/world-codesprint-7/challenges/two-characters
// Two Characters
#include <iostream>
#include <string>
#include <set>

using namespace std;

int n;
string str;
set<char> s;

bool ok(char a, char b) {
    char now = '0';

    for (char c : str) {
        if (c != a && c != b) continue;
        if (now == c) return false;
        now = c;
    }
    return true;
}

int len(char a, char b) {
    int r = 0;
    for (char c : str) {
        if (c == a || c == b) r++;
    }
    return r;
}

int main() {
    cin >> n >> str;

    for (char c : str) s.insert(c);

    int maxi = 0;
    for (char a : s) {
        for (char b : s) {
            if (a == b) continue;
            if (ok(a, b)) {
                maxi = max(maxi, len(a, b));
            }
        }
    }

    cout << maxi << endl;
    return 0;
}
