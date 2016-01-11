// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-11-more-review
// Day 11: 2D-Arrays + More Review!

#include <iostream>

using namespace std;

const int SIZE = 6;
int in[SIZE+4][SIZE+4] = {0, };

int main() {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            cin >> in[r][c];
        }
    }

    int best = -12345;
    for (int r = 0; r < SIZE-2; r++) {
        for (int c = 0; c < SIZE-2; c++) {
            int sum = 
                in[r][c] + in[r][c+1] + in[r][c+2] + 
                in[r+1][c+1] +
                in[r+2][c] + in[r+2][c+1] + in[r+2][c+2];
            best = max(best, sum);
        }
    }
    cout << best << endl;
    return 0;
}
