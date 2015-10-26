// https://www.lgcodechallenger.com
// problem 4
// O(MNRR)
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long int64;

int row, col, k, r;
int64 in [1500][1500];
//int out [1500][1500];

void input() {
    memset(in, 0, sizeof(in));
    scanf("%d %d %d %d", &col, &row, &k, &r);
    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; x++) {
            int temp;
            scanf("%d", &temp);
            in[y+r][x+r] = (1LL << temp);
        }
    }
}

int color_num(int rr, int cc) {
    int64 flag = 0;
    for (int y = rr - r; y <= rr + r; y++) {
        for (int x = cc - r; x <= cc + r; x++) {
            flag |= in[y][x];
        }
    }

    return __builtin_popcountll(flag);
}

void solve() {
    int maxi = 0;
    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; x++) {
            //out[y][x] = color_num(y, x);
            printf("%d ", color_num(y+r, x+r));
        }
        printf("\n");
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}
