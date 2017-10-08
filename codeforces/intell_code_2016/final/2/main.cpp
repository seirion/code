#include <iostream>
#include <vector>

using namespace std;

int row, col;
vector<vector<int>> in;

bool ok(vector<int> &v, int a, int b) {
    int num = 0;
    if (a != -1) swap(v[a], v[b]);
    for (int c = 0; c < col; c++) {
        if (v[c] != c+1) num++;
    }
    if (a != -1) swap(v[a], v[b]);
    return num <= 2;
}

bool ok(vector<vector<int>> &v, int a, int b) {
    for (int r = 0; r < row; r++) {
        if (!ok(v[r], a, b)) return false;
    }
    return true;
}

int main() {
    cin >> row >> col;
    in.resize(row);
    for (int r = 0; r < row; r++) {
        in[r].resize(col);
        for (int c = 0; c < col; c++) {
            cin >> in[r][c];
        }
    }

    if (ok(in, -1, -1)) goto YES;
    for (int a = 0; a < col; a++) {
        for (int b = a+1; b < col; b++) {
            if (ok(in, a, b)) goto YES;
        }
    }

    cout << "NO\n";
    return 0;
YES:
    cout << "YES\n";
    return 0;
}

