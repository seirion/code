// https://www.facebook.com/hackercup/problem/180494849326631/
// Facebook Hacker Cup 2018 Round 1
// Let It Flow
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const long long MOD = 1000000007LL;
int n;
string in[3];
long long v0[3][1000];
long long v1[3][1000];

void input() {
    memset(v0, 0, sizeof(v0));
    memset(v1, 0, sizeof(v1));
    cin >> n;
    for (int i = 0; i < 3; i++) cin >> in[i];
}

void go(int r, int c, int from) { // from 0 : -- row direction)
    if (in[r][c] == '#') return;

    if (from == 0) { // --
        if (0 < c) v0[r][c] = (v0[r][c] + v1[r][c-1]) % MOD;
    } else { // |
        if (0 < r) v1[r][c] = (v1[r][c] + v0[r-1][c]) % MOD;
        if (r < 2) v1[r][c] = (v1[r][c] + v0[r+1][c]) % MOD;
    }
}

void solve(int no) {
    if (in[0][0] != '#') v0[0][0] = 1;

    for (int c = 0; c < n; c++) {
        go(0, c, 0);
        go(1, c, 0);
        go(2, c, 0);
        go(0, c, 1);
        go(1, c, 1);
        go(2, c, 1);
    }
    cout << "Case #" << no << ": " << v1[2][n-1] << endl;
}

int main() {
    int c; cin >> c;
    for (int i = 1; i <= c; i++) {
        input();
        solve(i);
    }
    return 0;
}
