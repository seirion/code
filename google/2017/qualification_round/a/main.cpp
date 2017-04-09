// https://code.google.com/codejam/contest/3264486/dashboard#s=p0
// Problem A. Oversized Pancake Flipper
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int n;
string s;

void solve() {
    cin >> s >> n;

    int r = 0;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        if (s[i] == '+') continue;

        if (size < i + n) {
            cout << "IMPOSSIBLE\n";
            return;
        }

        for (int x = i, limit = i + n; x < limit; x++) {
            if (s[x] == '+') s[x] = '-';
            else s[x] = '+';
        }
        r++;
    }

    cout << r << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}

