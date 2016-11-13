// https://algospot.com/judge/problem/read/AMUSEMENTPARK
#include <iostream>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

int row, col;
int in[22][22] = {0, };
map<int, pair<int, int>> m;
vector<int> out;

bool cc(int r, int b, int d) {
    for (int i = b + 1; i < d; i++) {
        if (in[r][i] != 0) return false;
    }
    return true;
}

bool rr(int C, int a, int c) {
    for (int i = a + 1; i < c; i++) {
        if (in[i][C] != 0) return false;
    }
    return true;
}

int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

bool ok(int me, int to) {
    auto a = m[me].first;
    auto b = m[me].second;
    auto c = m[to].first;
    auto d = m[to].second;
    
    if (a == c) { return cc(a, min(b, d), max(b, d)); }
    if (b == d) { return rr(b, min(a, c), max(a, c)); }

    int dr = (c-a);
    int dc = (d-b);
    if (abs(dr) == 1 || abs(dc) == 1) return true;
    else {
        int g = gcd((int)abs(dr), (int)abs(dc));
        dr = dr / g;
        dc = dc / g;
        int rr = a + dr;
        int cc = b + dc;
        while (rr != c) {
            if (in[rr][cc] != 0) return false;
            rr += dr;
            cc += dc;
        }
        return true;
    }
}

int main() {
    int to;
    cin >> row >> col >> to;
    for (int r = 1; r <= row; r++) {
        for (int c = 1; c <= col; c++) {
            cin >> in[r][c];
            if (in[r][c] != 0) {
                m[in[r][c]] = make_pair(r, c);
            }
        }
    }

    int me(1);
    int maxi = in[row][col];
    while (to <= maxi) {
        if (ok(me, to)) out.push_back(me);
        me++; to++;
    }

    cout << out.size() << endl;
    for (int x : out) cout << x << endl;
    return 0;
}
