// https://www.hackerrank.com/contests/world-codesprint-7/challenges/summing-pieces
// Summing Pieces
// O(n^2) solution
#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;
int n;
long long in[1000001] = {0, };
long long m[1000001] = {0, };
long long pre[1000001] = {0, };


void build() {
    pre[0] = pre[1] = 1;
    for (int i = 2; i <= 1000000; i++) pre[i] = pre[i-1] * 2 % MOD;
}

long long base(int limit) {
    long long r = 1;
    for (int i = 1; i < limit; i++) r = (r * 2 + 1) % MOD;
    return r;
}

void make() {

    m[0] = m[n-1] = base(n);
    int size = (n + 1) / 2;
    long long x = 1;
    for (int i = 1; i < size; i++) {
        long long more = pre[n-i] - pre[i];
        m[n-1-i] = m[i] = (m[i-1] + more) % MOD;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];

    build();
    make();

    long long r = 0;
    for (int i = 0; i < n; i++) {
        long long temp = m[i] * in[i] % MOD;
        r = (r + temp) % MOD;
    }

    cout << r << endl;
    return 0;
}
