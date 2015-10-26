// https://www.lgcodechallenger.com
// problem 4
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef unsigned long long int64;

int row, col, k, r;
int in [502][502];
int count [502][502][52];

void input() {
    memset(in, 0, sizeof(in));
    memset(count, 0, sizeof(count));

    scanf("%d %d %d %d", &col, &row, &k, &r);
    for (int y = 1; y <= row; y++) {
        for (int x = 1; x <= col; x++) {
            scanf("%d", &in[y][x]);
        }
    }
}

void solve() {
    for (int y = 1; y <= row; y++) {
        for (int x = 1; x <= col; x++) {
            for (int i = 1; i <= k; i++) {
                count[y][x][i] = count[y][x-1][i]
                               + count[y-1][x][i]
                               - count[y-1][x-1][i]
                               + (in[y][x] == i ? 1 : 0);
            }
        }
    }

    for (int y = 1; y <= row; y++) {
        for (int x = 1; x <= col; x++) {
            int num_of_color = 0;
            for (int i = 1; i <= k; i++) {
                int num_of_k = count[min(y + r, row)][min(x + r, col)][i]
                             - count[min(y + r, row)][max(x - r - 1, 0)][i]
                             - count[max(y - r - 1, 0)][min(x + r, col)][i]
                             + count[max(y - r - 1, 0)][max(x - r - 1, 0)][i];
                if (num_of_k > 0) num_of_color++;
            }
            printf("%d ", num_of_color);
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
