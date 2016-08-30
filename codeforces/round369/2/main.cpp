#include <iostream>
#include <numeric>

using namespace std;

typedef long long int64;

int64 n;
int64 in[500][500];
int64 row, col;
int64 rr[500] = {0, }, cc[500] = {0, };
int64 xx, yy;

void input() {
    cin >> n;
    for (int64 r = 0; r < n; r++) {
        for (int64 c = 0; c < n; c++) {
            cin >> in[r][c];
            if (in[r][c] == 0) { row = r; col = c; }
        }
    }
}

int64 possible() {
    if (rr[row] != cc[col]) return -1;
    if (row == col && rr[row] != xx) return -1;
    if (row + col == n- 1 && rr[row] != yy) return -1;

    return row == 0 ? rr[row+1] - rr[row] : rr[0] - rr[row];
}

bool check() {
    for (int64 r = 0; r < n; r++) {
        rr[r] = 0;
        for (int64 c = 0; c < n; c++) {
            rr[r] += in[r][c];
        }
    }

    for (int64 c = 0; c < n; c++) {
        cc[c] = 0;
        for (int64 r = 0; r < n; r++) {
            cc[c] += in[r][c];
        }
    }

    xx = yy = 0;
    for (int64 i = 0; i < n; i++) xx += in[i][i];
    for (int64 i = 0; i < n; i++) yy += in[i][n-i-1];

    if (xx != yy) return false;
    for (int64 i = 0; i < n; i++) {
        if (xx != rr[i] || xx != cc[i]) return false;
    }
    return true;
}

void solve() {
    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    for (int64 r = 0; r < n; r++) {
        for (int64 c = 0; c < n; c++) {
            rr[r] += in[r][c];
        }
    }

    for (int64 c = 0; c < n; c++) {
        for (int64 r = 0; r < n; r++) {
            cc[c] += in[r][c];
        }
    }

    xx = yy = 0;
    for (int64 i = 0; i < n; i++) xx += in[i][i];
    for (int64 i = 0; i < n; i++) yy += in[i][n-i-1];

    long long out = possible();
    if (out == -1) cout << out << endl;
    else {
        in[row][col] = out;
        if (!check()) out = -1;
        if (out == 0) out = -1;
        cout << out << endl;
    }
}

int main() {
    input();
    solve();
    return 0;
}
