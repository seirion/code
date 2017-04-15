// https://code.google.com/codejam/contest/5304486/dashboard#s=p0
// Problem A. Alphabet Cake
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int row, col;
vector<string> in;
set<char> checked;

class R { public:
    R(int l, int r, int t, int b) : left(l), right(r), top(t), bottom(b) {}
    int left, right, top, bottom;
};

bool ok_left(R &rect, char x) {
    if (rect.left == 0) return false;

    int c = rect.left - 1;
    for (int r = rect.top; r <= rect.bottom; r++) {
        if (in[r][c] != '?') return false;
    }
    return true;
}

bool ok_right(R &rect, char x) {
    if (rect.right + 1 == col) return false;

    int c = rect.right + 1;
    for (int r = rect.top; r <= rect.bottom; r++) {
        if (in[r][c] != '?') return false;
    }
    return true;
}

bool ok_up(R &rect, char x) {
    if (rect.top == 0) return false;

    int r = rect.top - 1;
    for (int c = rect.left; c <= rect.right; c++) {
        if (in[r][c] != '?') return false;
    }
    return true;
}

bool ok_down(R &rect, char x) {
    if (rect.bottom + 1 == row) return false;

    int r = rect.bottom + 1;
    for (int c = rect.left; c <= rect.right; c++) {
        if (in[r][c] != '?') return false;
    }
    return true;
}

void fill(const R &rect, char x) {
    for (int c = rect.left; c <= rect.right; c++) {
        for (int r = rect.top; r <= rect.bottom; r++) {
            in[r][c] = x;
        }
    }
}

void go(int r, int c, char x) {
    checked.insert(x);
    R rect(c, c, r, r);

    // left
    while (ok_left(rect, x)) {
        rect.left--;
        fill(rect, x);
    }
    // right
    while (ok_right(rect, x)) {
        rect.right++;
        fill(rect, x);
    }
    // up
    while (ok_up(rect, x)) {
        rect.top--;
        fill(rect, x);
    }
    // down
    while (ok_down(rect, x)) {
        rect.bottom++;
        fill(rect, x);
    }
}

void solve() {
    checked.clear();

    cin >> row >> col;
    in.resize(row);
    for (int i = 0; i < row; i++) {
        cin >> in[i];
    }

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            char x = in[r][c];
            if (x != '?' && checked.find(x) == checked.end()) {
                go(r, c, x);
            }
        }
    }

    // output
    for (int r = 0; r < row; r++) cout << in[r] << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d:\n", i);
        solve();
    }
}

