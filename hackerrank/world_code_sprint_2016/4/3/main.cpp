// World CodeSprint
// Ema's Supercomputer
// https://www.hackerrank.com/contests/worldcodesprint/challenges/two-pluses
#include <iostream>
#include <cstdio>

using namespace std;

int row, col;
char in[20][20] = {0, };

void input() {
    scanf("%d %d\n", &row, &col);
    for (int i = 1; i <= row; i++) {
        fgets(in[i]+1, 19, stdin);
    }
}

void set(const int r, const int c, int size, char value) {
    in[r][c] = value;
    for (int i = 1; i <= size; i++) {
        in[r+i][c] = in[r][c+i] = value;
        in[r-i][c] = in[r][c-i] = value;
    }
}

int check(int num) {
    int best = 0;

    for (int r = 1; r <= row; r++) {
        for (int c = 1; c <= col; c++) {
            if (in[r][c] != 'G') continue;
            int size = 0;
            do {
                if (num == 0) {
                    set(r, c, size, 'B');
                    best = max(best, (1+size*4) * check(1));
                    set(r, c, size, 'G');
                }
                else {
                    best = max(best, 1+size*4);
                }
                size++;
            } while (in[r+size][c] == 'G' && in[r][c+size] == 'G' &&
                     in[r-size][c] == 'G' && in[r][c-size] == 'G');
        }
    }
    return best;
}

int main() {
    input();
    cout << check(0) << endl;
    return 0;
}
