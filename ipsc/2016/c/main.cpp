// https://ipsc.ksp.sk/2016/real/problems/c.html
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MOD = 1e9 + 9;

int n;
int in[100000];
bool visit[100000] = {false, };
long long fact[100001] = {0, };

void build() {
    fact[1] = fact[2] = 1;
    for (int i = 3; i <= 100000; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
}

int check(int now) {
    int r = 0;
    while (!visit[now]) {
        r++;
        visit[now] = true;
        now = in[now];
    }
    return r;
}

long long power(long long base, long long p) {
    if (p == 1) return base;

    long long res = power(base, p>>1);
    res = (res * res) % MOD;
    if (p & 1) res = res * base % MOD;
    return res;
}

long long inv(int x) {
    return power(x, MOD-2);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        in[i]--; // make 0-based
    }

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int c = check(i);
        if (1 < c) v.push_back(c-1);
    }
    //if (2 < v.size()) cout << "-------------------------------\n";

    long long r = 1;
    long long sum = 0;
    for (int x : v) {
        r = r * fact[x+1] % MOD;
        sum += x;
    }

    if (2 <= sum) {
        r = r * fact[sum] * 2 % MOD;

        long long xx = 1;
        for (int x : v) {
            if (2 <= x) xx = xx * fact[x] * 2 % MOD;
        }

        r = r * inv(xx) % MOD;
    }

    cout << r << endl;

    memset(visit, 0, sizeof(visit));
}

int main() {
    build();
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
