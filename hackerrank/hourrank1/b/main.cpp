// https://www.hackerrank.com/contests/hourrank-1/challenges/xor-groups
#include <iostream>

using namespace std;
typedef long long int64;

const int64 MOD = 1000000007LL;
int64 factorial[500001];

void make_factorials(int n) {
    factorial[0] = factorial[1] = 1;
    for (int i = 2; i <= n; i++) {
        factorial[i] = factorial[i-1] * i % MOD;
    }
}

void cal(int64 quotient , int64 &r, int64 &new_r) {
    int64 temp(r);
    r = new_r;
    new_r = temp - quotient * new_r;
}

int64 inverse(int64 a, int64 m = MOD) { // modular multiplicative inverse
    int64 t(0), new_t(1), r(m), new_r(a);
    while (new_r) {
        int64 quotient = r / new_r;
        cal(quotient, t, new_t);
        cal(quotient, r, new_r);
    }
    //return -1; // something wrong
    if (t < 0) t = t + m;
    return t;
}

int64 combination(int n, int r) {
    return factorial[n] * inverse(factorial[r]) % MOD * inverse(factorial[n-r]) % MOD;
}

int64 cases(int n) {
    int64 sum = 0;
    for (int r = 1; r < n; r++) {
        sum = (sum + combination(n, r)) % MOD;
    }
    return sum * inverse(2) % MOD;
}

int main() {
    int n; cin >> n;
    int one; cin >> one;
    int another = 0;
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        another ^= x;
    }

    if (one == another) {
        make_factorials(n);
        cout << cases(n) << endl;
    }
    else cout << 0 << endl;
    return 0;
}
