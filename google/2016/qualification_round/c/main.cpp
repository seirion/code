// https://code.google.com/codejam/contest/6254486/dashboard#s=p2
// Problem C. Coin Jam
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
typedef unsigned int uint32;

int n, k;
int ans[11];

bool devidable(long long now, int x, int base) {
    int num = 0;
    while (now) {
        num = base * num;
        if (now & 1) num++;
        now >>= 1;
        num %= x;
    }
    return (num == 0);
}

void solve() {
    cin >> n >> k;
    const uint32 LIMIT = (1 << (n-2));

    for (int i = 0; i < LIMIT; i++) {
        long long mask = (1LL << (n-1)) | (i << 1) | 1;
        memset(ans, 0xFF, sizeof(ans));
        bool ok = false;
        for (int x = 2; x < 10000; x++) {
            for (int base = 2; base <= 10; base++) {
                if (ans[base] != -1) continue;
                if (devidable(mask, x, base)) {
                    ans[base] = x;
                    break;
                }
            }
            ok = true;
            for (int base = 2; base <= 10; base++) {
                if (ans[base] == -1) { ok = false; break; }
            }
            if (ok) break;
        }

        if (ok) {
            while (mask) {
                cout << (mask & 1);
                mask >>= 1;
            }
            for (int base = 2; base <= 10; base++) {
                cout << " " << ans[base];
            }
            cout << "\n";
            if (--k == 0) break;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d:\n", i);
        solve();
    }
}

