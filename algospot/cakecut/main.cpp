// http://algospot.com/judge/problem/read/CAKECUT
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int memo[21][21][21];

void build() {
    for (int w = 1; w <= 20; w++) {
        for (int h = 1; h <= 20; h++) {
            memo[w][h][0] = w * h;
            for (int m = 1; m <= 20; m++) {

                int maxw = w; // w / 2
                for (int ww = 1; ww < maxw; ww++) { // for width

                    int maxm = m; // m / 2
                    for (int mm = 0; mm < maxm; mm++) { // various m
                        int temp = max(memo[ww][h][mm], memo[w-ww][h][m-1-mm]);
                        memo[w][h][m] = min(temp, memo[w][h][m]);
                    }

                }
                if (w == h) continue;
                int maxh = h; // h / 2
                for (int hh = 1; hh < maxh; hh++) { // for 

                    int maxm = m; // m / 2
                    for (int mm = 0; mm < maxm; mm++) { // various m
                        int temp = max(memo[w][hh][mm], memo[w][h-hh][m-1-mm]);
                        memo[w][h][m] = min(temp, memo[w][h][m]);
                    }

                }
            }
        }
    }
}

int cake_cut(int w, int h, int m) {
    return memo[w][h][m-1];
}

int main() {
    memset(memo, 0x7F, sizeof(int) * 21 * 21 * 21);
    build();
    while (true) {
        int w, h, m;
        scanf("%d %d %d", &w, &h, &m);
        if (w == 0 && h == 0 && m == 0) break;
        printf ("%d\n", cake_cut(w, h, m));
    }
    return 0;
}
