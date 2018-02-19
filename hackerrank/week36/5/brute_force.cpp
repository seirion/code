#include <iostream>

using namespace std;

int row, col, k;
int in[400][400];
int sum[400][400] = {0, };
int best = 0xFFFFFFFF;

void input() {
    cin >> row >> col >> k;
    for (int r = 1; r <= row; r++) for (int c = 1; c <= col; c++) {
        cin >> in[r][c];
        sum[r][c] = in[r][c];
        sum[r][c] += sum[r-1][c] + sum[r][c-1] - sum[r-1][c-1];
    }
}

inline int sumof(int r1, int r2, int c1, int c2) { // [r1, r2]
    return sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1];
}

void go(int r1, int r2, int c1, int c2) {
    int s = sumof(r1, r2, c1, c2);

    for (int r3 = r1; r3 <= r2; r3++) {
        for (int r4 = r3; r4 <= r2 && r4-r3+1 <= k; r4++) {
            for (int c3 = c1; c3 <= c2; c3++) {
                    int ss = sumof(r3, r4, c3, c3);
                    best = max(best, s - ss);
            }
        }
    }

    for (int c3 = c1; c3 <= c2; c3++) {
        for (int c4 = c3; c4 <= c2 && c4-c3+1 <= k; c4++) {
            for (int r3 = r1; r3 <= r2; r3++) {
                    int ss = sumof(r3, r3, c3, c4);
                    best = max(best, s - ss);
            }
        }
    }
}

void solve() {
    for (int r1 = 1; r1 <= row; r1++) {
        for (int r2 = r1; r2 <= row; r2++) {
            for (int c1 = 1; c1 <= col; c1++) {
                for (int c2 = c1; c2 <= col; c2++) {
                    go(r1, r2, c1, c2);
                }
            }
        }
    }
    cout << best << endl;
}

int main() {
    input(); solve();
    return 0;
}
