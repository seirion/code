// codeforces round320
// http://codeforces.com/contest/579/problem/D
#include <iostream>
#include <algorithm>

using namespace std;

int n, k, x;
int in[200001];
int flags[64] = {0, };

void put(long long a, int add = 1) {
    while (a) {
        int index = __builtin_ctzll(a);
        flags[index] += add;
        a &= a-1;
    }
}

long long make() {
    long long r(0);
    for (int i = 63; i >= 0; i--) {
        r = (r << 1) + (flags[i] ? 1 : 0);
    }
    return r;
}

long long power(int base, int times) {
    long long r = 1;
    for (int i = 0; i < times; i++) r *= base;
    return r;
}

void shift() {
    for (int i = 0; i < n; i++) cin >> in[i];
    for (int i = 0; i < n; i++) put(in[i]);

    long long maxi = 0;
    for (int i = 0; i < n; i++) {
        long long now = in[i] * power(x, k);
        put(in[i], -1); // substract
        put(now);
        maxi = max(maxi, make());
        put(now, -1);
        put(in[i]);
    }
    cout << maxi << endl;
}

int main() {
    cin >> n >> k >> x;

    shift();
    return 0;
}
