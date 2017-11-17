#include <iostream>

using namespace std;

int row, col;

int in[102][102] = {0, };

int main() {
    cin >> row >> col;

    int ss = 0;
    for (int r = 1; r <= row; r++) {
        for (int c = 1; c <= col; c++) {
            cin >> in[r][c];
            if (in[r][c] != 0) ss += 2;
        }
    }

    int t;
    for (int r = 1; r <= row; r++) {
        for (int c = 1; c <= col; c++) {
            t = in[r][c] - in[r][c-1]; // left
            if (0 < t) ss += t;
            t = in[r][c] - in[r][c+1]; // right
            if (0 < t) ss += t;
            t = in[r][c] - in[r-1][c]; // up
            if (0 < t) ss += t;
            t = in[r][c] - in[r+1][c]; // down
            if (0 < t) ss += t;
        }
    }

    cout << ss << endl;
    return 0;
}
