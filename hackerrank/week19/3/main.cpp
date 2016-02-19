// https://www.hackerrank.com/contests/w19/challenges/scalar-products
// Scalar Products
#include <iostream>
#include <set>

using namespace std;

long long C, MOD, n;

long long fib[1200000 + 3];

void calc_fib() {
    fib[0] = 0; fib[1] = 1;
    int size = n * 4;
    for (int i = 2; i <= size; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }
}

void solve() {
    long long res = 1;
    set<int> s;

    int x = 7;
    int limit = (n-1) * 2 - 1;
    for (int i = 0; i < limit; i++, x+=2) {
        long long temp = fib[x];
        temp = (temp * C) % MOD;
        temp = (temp * C) % MOD;

        if (s.find(temp) == s.end()) {
            s.insert(temp);
            res = (res * temp) % MOD;
        }
    }

    cout << s.size() << endl;
}

int main() {
    cin >> C >> MOD >> n;
    calc_fib();
    solve();
    return 0;
}
