// http://codeforces.com/contest/644/problem/A
// CROC 2016 - Qualification
// A. Parliament of Berland
#include <iostream>

using namespace std;

int n, row, col;
int out[102][102] = {0, };

void print() {
    for (int r = 1; r <= row; r++) {
        for (int c = 1; c <= col; c++) {
            cout << out[r][c] << " ";
        }
        cout << endl;
    }
}

bool fill(int r, int c, int odd, int even) {
    if (n < odd && n < even) {
        print();
        return true;
    }

    if (col < c) {
        r++;
        c -= col;
    }

    if (row < r) {
        return false;
    }

    // odd
    int &up = out[r-1][c];
    int &left = out[r][c-1];
    if (odd <= n && (up == 0 || !(up & 1)) && (left == 0 || !(left & 1))) {
        out[r][c] = odd;
        if (fill(r, c+1, odd+2, even)) return true;
    }
    // even
    if (even <= n && (up == 0 || up & 1) && (left == 0 || left & 1)) {
        out[r][c] = even;
        if (fill(r, c+1, odd, even+2)) return true;
    }
    // 0
    out[r][c] = 0;
    if (fill(r, c+1, odd, even)) return true;
    return false;
}

int main() {
    cin >> n >> row >> col;
    if (!fill(1, 1, 1, 2)) {
        cout << -1 << endl;
    }
    return 0;
}
