// http://algospot.com/judge/problem/read/DIAMOND
#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;

char in[50][51];
int count[50][50];
int width, height;
int solution;

void getInput() {
    scanf("%d\n", &height);
    width = 0;
    for (int i = 0; i < height; i++) {
        gets(in[i]);
        width = max(width, (int)strlen(in[i]));
    }
}

void preprocess() {
    for (int r = 0; r < height; r++) {
        count[r][0] = (in[r][0] == '#') ? 1 : 0;
        for (int c = 1; c < width; c++) {
            if (in[r][c] == '#') count[r][c] = count[r][c-1] + 1;
            else count[r][c] = 0;
        }
    }
}

void max_square() {
    solution = 0;
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            if (count[r][c] > solution) {

                solution = max(solution, 1);
                int current = (count[r][c]-1) / 2 * 2 + 1;
                int prev = current;
                int h = 1;
                int up(r-1), down(r+1);
                for (; up >= 0 && down < height; up--, down++, h++) {

                    current = min(count[up][c-h], count[down][c-h]);
                    if (current > 0 && current % 2 == 0) current--;

                    current = min (prev - 2, current);
                    if (current >= 1) {
                        solution = max(solution, (h + 1) * 2 - 1);
                    }
                    else break;
                    prev = current;
                }
            }
        }
    }
    printf("%d\n", solution);
}

void solve() {
    //memset(in, 0, sizeof(char) * 50 * 51);
    getInput();
    preprocess();
    max_square();
}

int main() {
    int num;
    scanf("%d\n", &num);
    for (int i = 0; i < num; i++) solve();
    return 0;
}
