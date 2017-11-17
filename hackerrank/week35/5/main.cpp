#include <iostream>

using namespace std;

const long long MOD = 1000000009LL;
const long long MAX_N = 1002;

long long n, k;
long long F[MAX_N][MAX_N], nk[MAX_N];
long long inv[MAX_N];
long long in[MAX_N][MAX_N];

void build_comb() {
    for (int i = 0; i < MAX_N; i++) {
        in[i][0] = 1;
        in[i][i] = 1;
    }
    for (int i = 2; i < MAX_N; i++) {
        for (int j = 1; j < i; j++) {
            in[i][j] = (in[i - 1][j - 1] + in[i - 1][j]) % MOD;
        }
    }
    inv[0] = inv[1] = 1;
    for (int i = 2; i < MAX_N; i++) {
        inv[i] = (-1LL * (MOD / i) * inv[MOD % i]) % MOD + MOD;
        if (inv[i] < 0) cout << " !!!!!!!!!!!!!!!!!!\n";
    }
}

void build() {
    F[0][0] = 1;
    F[1][0] = F[1][1] = inv[2];
    for (int i = 2; i < MAX_N - 1; i++) {
        F[i][0] = i + 1;
        for (int j = 0;j < i; j++) {
            F[i][0] = (F[i][0] - in[i + 1][j] * F[j][0]) % MOD;
        }
        F[i][0] = (F[i][0] * inv[i + 1]) % MOD;
        if(F[i][0] < 0) {
            F[i][0] += MOD;
        }
        for (int j = 1; j <= i; j++) {
            F[i][j] = ((((F[i - 1][j - 1] * i) % MOD) * inv[j+1]) % MOD);
        }
    }
}

long long faulhaber(int k) {
    long long an = 0;
    for (int i = 0; i <= k; i++) {
        an = (an + F[k][i] * nk[i]) % MOD;
    }
    return an;
}

// Faulhaber's formula
void solve() {
    nk[0] = n;
    for (int i = 1; i <= k + 2; i++) {
        nk[i] = (nk[i - 1] * n) % MOD;
    }

    cout << (faulhaber(k) + MOD - 1LL) % MOD << endl;
}

int main() {
    build_comb();
    build();

    int q; cin >> q;
    while (q--) {
        cin >> n >> k; n--;
        n %= MOD;
        if (n == 0) cout << 0 << endl;
        else solve();
    }
    return 0;
}
