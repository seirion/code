// https://www.hackerrank.com/contests/w23/challenges/lighthouse
// Lighthouse
#include <cstdio>
#include <iostream>

using namespace std;

int n, best(0);
char in[52][52] = {0, };
int cc[52][52] = {0, }; // running empty

void input() {
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) gets(in[i]+1);
}

bool ok(int row, int col, int num) {
    int h(1), w(num); // height width
    const int limit = num * num;

    int length(num*2+1);
    while (h <= num) {
        while (0 <= w && limit < (h*h + w*w)) {
            w--;
            length -= 2;
        }
        if (w < 0) break;
        int now = min(length, cc[row-h][col-num+w]);
        now = min(now, cc[row+h][col-num+w]);
        if (now < length) return false;

        h++;
    }
    return true;
}

void find(int row, int col) {
    int num = cc[row][col];
    int begin = best + 1;
    int end = (num - 1) / 2;


    for (int i = begin; i <= end; i++) {
        if (ok(row, col, i)) best = i;
        else break;
    }
}

void solve() {
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            if (in[r][c] == '.') cc[r][c] = cc[r][c-1]+1;
            else cc[r][c] = 0;
        }
    }

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            find(r, c);
        }
    }
    printf("%d\n", best);
}

int main(){
    input();
    solve();
    return 0;
}
