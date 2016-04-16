// https://code.google.com/codejam/contest/4304486/dashboard#s=p1&a=2
// Problem B. Rank and File
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n;

void solve() {
    map<int, int> m;

    cin >> n;
    vector<vector<int>> in;
    in.resize(2*n-1);
    int size = in.size();
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < n; c++) {
            int x; cin >> x;
            m[x]++;
        }
    }

    for (auto x : m) {
        if (x.second & 1) cout << x.first << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}

