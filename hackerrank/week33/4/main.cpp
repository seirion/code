#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;

int best = 1;
int aa(1), bb(1), cc(1), dd(1);
int row, col;
vector<vector<int>>v;
vector<vector<int>>num;

inline bool big(int a, int b, int c, int d) {
    return best < (c-a+1) * (d-b+1);
}

bool ok(int a, int b, int c, int d) {
    int flag = v[a-1][b-1] ^ v[a-1][d] ^ v[c][b-1] ^ v[c][d];
    int nonZero = num[c][d] - num[a-1][d] - num[c][b-1] + num[a-1][b-1];
    return __builtin_popcount(flag) <= 1 && 2 <= nonZero;
}

int main() {
    scanf("%d %d\n", &row, &col);
    v.resize(row+1);
    num.resize(row+1);
    v[0].resize(col+1, 0);
    num[0].resize(col+1, 0);
    for (int r = 1; r <= row; r++) {
        v[r].resize(col+1, 0);
        num[r].resize(col+1, 0);
        for (int c = 1; c <= col; c++) {
            int x; scanf("%d\n", &x);
            v[r][c] = v[r-1][c] ^ v[r][c-1] ^ v[r-1][c-1] ^ (1 << x);
            num[r][c] = num[r-1][c] + num[r][c-1] - num[r-1][c-1] + (x == 0 ? 0 : 1);
        }
    }

    for (int c = row; c >= 1; c--) {
        if (!big(1, 1, c, col)) continue;

        for (int d = col; d >= 1; d--) {
            if (!big(1, 1, c, d)) continue;
            if (num[c][d] <= 1) continue;

            for (int a = c; 1 <= a; a--) {
                for (int b = d; 1 <= b; b--) {
                    if (big(a, b, c, d) && ok(a, b, c, d)) {
                        best = (c-a+1) * (d-b+1);
                        aa = a; bb = b; cc = c; dd = d;
                    }
                }
            }
        }
    }

    cout << best << endl << aa-1 << " " << bb-1 << " " << cc-1 << " " << dd-1 << endl;
    return 0;
}
