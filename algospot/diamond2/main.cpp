// http://algospot.com/judge/problem/read/DIAMOND2
#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;

char in[400][401];
int count[400][400];
int width, height;
int solution;

void input() {
    scanf("%d\n", &height);
    width = 0;
    for (int i = 0; i < height; i++) {
        gets(in[i]);
    }
    width = strlen(in[0]);
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

void count_diamond() {
    solution = 0;
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {

            int current = count[r][c];
            if (current == 0) continue;
            
            solution++;
            current = (count[r][c]-1) / 2 * 2 + 1; // make it odd
            int prev = current;
            int h = 1;
            int up(r-1), down(r+1);
            for (; up >= 0 && down < height; up--, down++, h++) {

                current = min(count[up][c-h], count[down][c-h]);
                if (current > 0 && current % 2 == 0) current--;

                current = min (prev - 2, current);
                if (current >= 1) {
                    solution++;
                }
                else break;
                prev = current;
            }
        }
    }
    printf("%d\n", solution);
}

void solve() {
    input();
    preprocess();
    count_diamond();
}

int main() {
    int num;
    scanf("%d\n", &num);
    for (int i = 0; i < num; i++) solve();
    return 0;
}
