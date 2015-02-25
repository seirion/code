// http://codeforces.com/contest/515/problem/D
// D. Drazil and Tiles
#include <cstdio>
#include <iostream>
#include <cstring>
 
using namespace std;
 
enum {
    NONE = 0, UP, DOWN, RIGHT, LEFT, STAR,
};

int row, col;
int in[2001][2001];
int snapshot[2001][2001];
int way = 0;
int star = 0;

void input() {
    char buffer[2002];
    scanf("%d %d\n", &row, &col);
    for (int i = 0; i < row; i++) {
        gets(buffer);
        for (int j = 0; j < col; j++) {
            in[i][j] = (buffer[j] == '*' ? STAR : NONE);
            if (in[i][j] == STAR) star++;
        }
    }
}
 

void capture() {
    memcpy(snapshot, in, sizeof(int) * 2001 * 2001);
}

void cover(int r, int c) {
    while (r < row && in[r][c] != NONE) {
        int temp = r * col + c + 1; // row major
        r = temp / col;
        c = temp % col; 
    }

    if (r == row) { // full (finish condition)
        way++;
        if (way == 1) capture();
        return;
    }
    //printf(" >> %d %d\n", r, c);// FIXME

    if (way > 1) return;
    if (c + 1 < col && in[r][c+1] == NONE) {
        in[r][c] = LEFT; in[r][c+1] = RIGHT;
        cover(r, c);
        in[r][c] = in[r][c+1] = NONE; // clear
    }
    if (way > 1) return;
    if (r + 1 < row && in[r+1][c] == NONE) {
        in[r][c] = UP; in[r+1][c] = DOWN;
        cover(r, c);
        in[r][c] = in[r+1][c] = NONE;
    }
}

void print() {
    const char CHAR [] = {
        '.', '^', 'v', '>', '<', '*'
    };
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c", CHAR[snapshot[i][j]]);
        }
        printf("\n");
    }
}

void solve() {
    if (star == row * col) {
        capture();
        print();
        return;
    }
    cover(0, 0);
    if (way == 1) {
        print();
        return;
    }
    printf("Not unique\n");
}
 
int main() {
    input();
    solve();
    return 0;
}
