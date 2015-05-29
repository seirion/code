// https://www.hackerrank.com/contests/w15/challenges/diagonal-queries
// Weekly Challenges - Week 15 Diagonal Queries 
// it is wrong code
#include <iostream>

using namespace std;

const int MOD = 1000000007;
int row, col;
int sum[200002] = {0, };

void input() {
}

void solve() {
}

void (*fn[26])(int, int);

void Qc(int c, int v) { 
    int s(v); c--;
    for (int i = row; i >= 1; i--) {
        sum[i+c] = (sum[i+c] + s) % MOD;
        s = (s+v) % MOD;
    }
}
void Qr(int r, int v) {
    int s(v); r--;
    for (int i = 0; i < col; i++) {
        sum[row-r+i] = (sum[row-r+i] + s) % MOD;
        s = (s+v) % MOD;
    }
}
void Qd(int from, int to) {
    int v(0);
    for (int i = from; i <= to; i++) {
        v = (v + sum[i]) % MOD;
    }
    cout << v << "\n";
}
void Qs(int r1, int c1, int r2, int c2, int v) {
    int from = row+1-r2    +    c1-1; // (r2, c1)
    int to = row+1-r1      +    c2-1; // (r1, c2);

    int i(from), s(0), h(r2-r1+1); // height
    for (; i <= h; i++) {
        s = (s+v) % MOD;
        sum[i] = (sum[i] + s) % MOD;
    }
    for (; i <= to; i++) {
        sum[i] = (sum[i] + s) % MOD;
    }
    s = (s + MOD - v) % MOD;
    for (i = 0; i < h; i++) {
        sum[to-i] = (sum[to-i] + MOD - s) % MOD;
        s = (s + MOD - v) % MOD;
    }
}

int main() {
    fn['c'-'a'] = Qc;
    fn['r'-'a'] = Qr;
    fn['d'-'a'] = Qd;

    int query;
    cin >> row >> col >> query;
    for (int i = 0; i < query; i++) {
        string s; int v[5];
        cin >> s;
        switch (s[1]) {
            case 's':
                cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];
                Qs(v[0], v[1], v[2], v[3], v[4]);
                break;
            default:
                cin >> v[0] >> v[1];
                fn[s[1]-'a'](v[0], v[1]);
                break;
        }
    }
    return 0;
}
