// https://code.google.com/codejam/contest/6254486/dashboard#s=p3
// Problem D. Fractiles
#include <cstdio>
#include <iostream>

using namespace std;

int k, c, s;

void solve() {
    cin >> k >> c >> s;

    if (s * c < k) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    int current = 0;
    int base = k;
    while (current < k) {
        long long now = 0;
        for (int i = 0; i < c; i++) {
            now = now * base + current;
            current++;
            if (k <= current) break;
        }
        cout << now + 1 << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}

