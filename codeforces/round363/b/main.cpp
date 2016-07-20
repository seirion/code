// http://codeforces.com/contest/699/problem/B
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

int row, col;
vector<pair<int, int>> m;
map<int, int> R, C;

void input() {
    cin >> row >> col;
    for (int r = 0; r < row; r++) {
        string str;
        cin >> str;
        for (int c = 0; c < col; c++) {
            if (str[c] == '*') {
                R[r]++;
                C[c]++;
                m.push_back(make_pair(r, c));
            }
        }
    }
}

int maxone(const map<int, int> &mm) {
    int maxi = 0;
    int maxv = 0;
    for (auto &x : mm) {
        if (maxv < x.second) {
            maxv = x.second;
            maxi = x.first;
        }
    }
    return maxi;
}

void solve() {
    if (m.empty()) {
        cout << "YES\n1 1\n";
        return;
    }

    int r = maxone(R);
    int c = maxone(C);

    int cc = 0;
    for (auto &x : m) {
        if (x.first == r || x.second == c) cc++;
    }

    if (cc == m.size()) {
        cout << "YES\n" << r+1 << " " << c+1 << endl;
    }
    else cout << "NO\n";
}

int main() {
    input();
    solve();
    return 0;
}
