// https://code.google.com/codejam/contest/dashboard?c=11254486#s=p2
// Problem C. Technobabble : solvable only small input
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int n;
vector<string> in;

int next(int v) {
    int t = (v | (v - 1)) + 1;
    return t | ((((t & -t) / (v & -v)) >> 1) - 1);
}

bool ok(int normal, int fake) {
    set<string> s1, s2;
    
    while (normal) {
        int i = __builtin_ctz(normal);
        s1.insert(in[i<<1]);
        s2.insert(in[i<<1|1]);
        normal &= normal - 1;
    }

    while (fake) {
        int i = __builtin_ctz(fake);
        if (s1.find(in[i<<1]) == s1.end() || s2.find(in[i<<1|1]) == s2.end()) return false;
        fake &= fake - 1;
    }
    return true;
}

int find_max() {
    int all = (1 << n) - 1;
    int now = (all >> 1);
    while (now) {
        if (ok(~now & all, now)) return __builtin_popcount(now);
        now = next(now) & all;
    }

    return 0;
}

void solve() {
    cin >> n;
    in.resize(n<<1);
    for (int i = 0; i < n; i++) {
        cin >> in[i<<1] >> in[i<<1|1];
    }

    cout << find_max() << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}

