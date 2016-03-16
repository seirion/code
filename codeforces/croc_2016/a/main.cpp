// http://codeforces.com/contest/644/problem/A
// CROC 2016 - Qualification
// A. Parliament of Berland
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, row, col;
int v[100][100] = {0, };

void print() {
    int index = 0;
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cout << v[r][c] << " ";
        }
        cout << endl;
    }
}


int main() {
    cin >> n >> row >> col;
    if (row*col < n) {
        cout << -1 << endl;
        return 0;
    }
    
    int index = 1;
    for (int r = 0; index <= n && r < row; r++)
        for (int c = 0; index <= n && c < col; c++)
            v[r][c] = index++;

    if (!(col & 1)) {
        for (int i = 1; i < row; i+=2) {
            reverse(v[i], v[i]+col);
        }
    }
    print();
    return 0;
}
