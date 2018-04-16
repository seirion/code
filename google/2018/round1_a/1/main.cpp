#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int row, col, rr, cc;
int total, each, reach;
char in[101][101];
int num[101][101]; // 격자 내 @ 수

int _num(int r, int c) { // inclusive
    if (r < 0 || c < 0) return 0;
    return num[r][c];
}

void input() {
    total = 0;
    memset(num, 0, sizeof(num));
    cin >> row >> col >> rr >> cc; rr++; cc++;
    for (int r = 0; r < row; r++) for (int c = 0; c < col; c++) {
        cin >> in[r][c];
        num[r][c] = _num(r-1, c) + _num(r, c-1) - _num(r-1, c-1);
        if (in[r][c] == '@') { total++; num[r][c]++; }
    }
    each = total / rr / cc;
    reach = total / rr;
}

bool check(const vector<int> &rv, const vector<int> &cv) {
    return true;
}

bool promissing_r(const vector<int> &rv) {
    auto it = rv.rbegin();
    int choco = _num(*it, col-1); it++;
    if (it != rv.rend()) choco -= _num(*it, col-1);
    return reach == choco; // 그 개수만큼 있어야 함
}

bool promissing_c(const vector<int> &rv, const vector<int> &cv) {
    auto it = cv.rbegin();
    int cto = *it; it++; // inclusive
    int cfrom = (it == cv.rend() ? -1 : (*it)+1); // inclusive
    int rfrom(-1), rto;

    for (auto &r: rv) {
        rto = r;
        int choco = _num(rto, cto)
            - _num(rfrom-1, cto) - _num(rto, cfrom-1) + _num(rfrom-1, cfrom-1);
        if (choco != each) return false;
        rfrom = r+1;
    }
    return true;
}

bool go(int rstart, int cstart, vector<int> &rv, vector<int> &cv) {
    if (rv.size() == rr && cv.size() == cc)
        return (rv.back() == row-1 && cv.back() == col-1);
    //if (rv.size() == rr && rv.back() != row-1) return false;
    //if (cv.size() == cc && cv.back() != col-1) return false;

    if (rv.size() < rr) {
        for (int r = rstart; r < row; r++) {
            rv.push_back(r);
            if (promissing_r(rv)) {
                if (go (r+1, cstart, rv, cv)) return true;
            }
            rv.pop_back();
        }
    } else if (cv.size() < cc) {
        for (int c = cstart; c < col; c++) {
            cv.push_back(c);
            if (promissing_c(rv, cv)) {
                if (go (rstart, c+1, rv, cv)) return true;
            }
            cv.pop_back();
        }
    }
    return false;
}

vector<int> a, b;
bool solve() {
    if (total == 0) return true;
    if (total % (rr * cc) != 0) return false;

    a.clear(); b.clear();
    return go(0, 0, a, b);
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        input();
        printf("Case #%d: %s\n", i, solve() ? "POSSIBLE" : "IMPOSSIBLE");
        for (auto x : a) cout << x; cout << endl;
    }
    return 0;
}
