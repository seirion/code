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
vector<int> prime;

bool is_prime(int p) {
    for (int i = 0; i < prime.size(); i++) if (p % prime[i] == 0) return false;
    return true;
}

void calc() {
    prime.push_back(2);
    for (int i = 3; i <= 10000; i+=2) {
        if (is_prime(i)) prime.push_back(i);
    }
}

void solve() {
    cin >> n >> k;
    const uint32 LIMIT = (1 << (n-2));

    for (int i = 0; i < LIMIT; i++) {
        long long mask = (1LL << (n-1)) | (i << 1) | 1;
        memset(ans, 0xFF, sizeof(ans));
        bool ok = false;
        for (int x : prime) {
            for (int base = 2; base <= 10; base++) {
                long long now = mask;
                int num = 0;
                while (now) {
                    num = base * num;
                    if (now & 1) num++;
                    now >>= 1;
                    num %= x;
                }
                if (num == 0 && ans[base] == -1) {
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
    calc();

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d:\n", i);
        solve();
    }
}

