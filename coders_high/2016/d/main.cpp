// https://www.acmicpc.net/problem/12793
// 블록 게임
#include <iostream>
#include <string>
#include <set>

using namespace std;

int BASE = 200;
int col, row, k, COL, ROW;
double kk;

string iin[202];
int in[202][202] = { 0, };

void input() {
    cin >> col >> row >> kk;
    k = (int)(kk * 2);
    COL = col * 2 + 1; ROW = row * 2 + 1;
    for (int r = 0; r < ROW; r++) cin >> iin[r];

    for (int r = 1; r < ROW; r++) {
        for (int c = 1; c < COL; c++) {
            in[r][c] = iin[r][c];
        }
    }
}

void process(int r, int c, int v) {
    if (in[r][c] != 'B') return;
    in[r][c] = v;

    if (in[r-1][c] == '.') process(r-2, c, v);
    if (in[r+1][c] == '.') process(r+2, c, v);
    if (in[r][c-1] == '.') process(r, c-2, v);
    if (in[r][c+1] == '.') process(r, c+2, v);
}

void ok(int rr, int cc, set<int> &out) {

    set<int> R, C;
    if (0 < rr-1) R.insert(rr-1);
    R.insert(rr);
    if (rr+1 < ROW) R.insert(rr+1);

    if (0 < cc-1) C.insert(cc-1);
    C.insert(cc);
    if (cc+1 < COL) C.insert(cc+1);

    for (int r : R) {
        for (int c : C) {
            if (BASE < in[r][c]) out.insert(in[r][c]);
        }
    }
}

void solve() {
    int v = 1 + BASE;
    for (int r = 1; r < ROW; r++) {
        for (int c = 1; c < COL; c++) {
            if (in[r][c] == 'B') {
                process(r, c, v);
                v++;
            }
        }
    }

    set<int> out;
    int rrr = -1;
    int ccc = -1;

    int rr(ROW-1), cc(k);
    do {
        if (k % 2 == 0) {
           if (BASE < in[rr][cc]) out.insert(in[rr][cc]);
        }
        else ok(rr, cc, out);

        if (rr == 0) rrr = 1;
        if (cc == 0) ccc = 1;
        if (cc == COL-1) ccc = -1;

        rr += rrr;
        cc += ccc;
    } while (rr < ROW);

    cout << out.size() << endl;
}

int main() {
    input();
    solve();
    return 0;
}
