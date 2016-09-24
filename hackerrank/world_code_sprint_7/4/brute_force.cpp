// https://www.hackerrank.com/contests/world-codesprint-7/challenges/summing-pieces
// Summing Pieces
// O(n^2) solution
#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;
int n;
long long in[1000001] = {0, };

long long pre[1000001] = {0, };

void build() {
    pre[0] = pre[1] = 1;
    for (int i = 2; i <= 1000000; i++) pre[i] = pre[i-1] * 2 % MOD;
}

int main() {
    build();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
        in[i] += in[i-1];
    }

    long long r = 0;
    for (int b = 1; b <= n; b++) {
        for (int a = 0; a < b; a++) {
            long long temp = pre[a] * (in[b]-in[a]) % MOD;
            temp = temp * (b-a) % MOD;
            temp = temp * pre[n-b] % MOD;
            r = (r + temp) % MOD;
        }
    }

    cout << r << endl;
    return 0;
}
