// https://code.google.com/codejam/contest/6224486/dashboard#s=p3
// Problem D. Ominous Omino

#include <cstdio>
#include <iostream>

using namespace std;

int solve() {
    int x, r, c; cin >> x >> r >> c;

    if ((r * c) % x != 0 ) return false;

    if (r < c) swap(r, c); // always R > C
    if (r < x) return false;

    switch (x) {
        case 1: return true;
        case 2: return true;
        case 3: return (c >= 2);
        case 4: return (c >= 3);
        case 5: return (c >= 3) && !(c == 3 && r == 5);
        case 6: return (c >= 4);
        default: return false; // X >= 7
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: %s\n", i, solve() ? "GABRIEL" : "RICHARD");
    }
    return 0;
}

