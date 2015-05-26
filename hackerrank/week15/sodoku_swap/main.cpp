// https://www.hackerrank.com/contests/w15/challenges/sudoku-swap
// Weekly Challenges - Week 15 Sudoku Swap 
#include <cstdio>
#include <vector>

using namespace std;

int in[9*9]; // row-major
vector<int> v[9]; // nine-cells

void init() {
    for (int i = 0; i < 9; i++) {
        v[i/3].push_back(i);
        v[i/3+3].push_back(i+27);
        v[i/3+6].push_back(i+54);
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 3; j++) {
            v[i].push_back(v[i][j]+9);
            v[i].push_back(v[i][j]+18);
        }
    }
}

void input() {
    for (int i = 0; i < 81; i++) {
        scanf("%d", &in[i]);
    }
}

bool valid(int from, int jump) {
    bool check[10] = {false, };
    for (int i = 0; i < 9; i++) {
        check[in[from + (i*jump)]] = true;
    }

    for (int i = 1; i <= 9; i++) {
        if (!check[i]) return false;
    }
    return true;
}

bool valid(const vector<int> &vv) {
    bool check[10] = {false, };
    for (int i = 0; i < 9; i++) {
        check[in[vv[i]]] = true;
    }

    for (int i = 1; i <= 9; i++) {
        if (!check[i]) return false;
    }
    return true;
}

bool valid() {
    for (int i = 0; i < 81; i+= 9) { // horizontal
        if (!valid(i, 1)) return false;
    }
    for (int i = 0; i < 9; i++) { // vertical
        if (!valid(i, 9)) return false;
    }

    for (int i = 0; i < 9; i++) { // vertical
        if (!valid(v[i])) return false;
    }
    return true;
}

void solve() {
    if (valid()) {
        printf("Serendipity\n");
        return;
    }

    for (int a = 0; a < 81; a++) {
        for (int b = a+1; b < 81; b++) {
            if (a == b || in[a] == in[b]) continue;
            swap(in[a], in[b]);
            if (valid()) {
                printf("(%d,%d) <-> (%d,%d)\n", a/9+1, a%9+1, b/9+1, b%9+1);
            }
            swap(in[a], in[b]); // recover
        }
    } 
}

int main() {
    init();
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d:\n", i);
        input();
        solve();
    }
    return 0;
}
