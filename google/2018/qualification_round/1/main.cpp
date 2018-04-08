#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

long long d;
string s;

long long all() {
    long long len = 1L;
    long long r = 0L;
    for (char &c : s) {
        switch (c) {
            case 'C' : len <<= 1; break;
            case 'S' : r += len; break;
        }
    }
    return r;
}

int latest() {
    for (int i = s.size() - 1; 1 <= i; i--) {
        if (s[i] == 'S' && s[i-1] == 'C') return i;
    }
    return -1;
}

int run(int to) {
    int r = 1;
    for (int i = 0; i <= to; i++) {
        if (s[i] == 'C') r++;
    }
    return r;
}

void solve() {
    long long now = all();
    int r = 0;

    while (true) {
        if (now <= d) break;
        int i = latest();
        if (i == -1) break;
        r++;
        now -= (1L << (run(i) - 2));
        swap(s[i], s[i-1]);
    }


    if (now <= d) {
        cout << r << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> d >> s;
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
