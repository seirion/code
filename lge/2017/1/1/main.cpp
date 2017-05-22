#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool ok(map<char, vector<int>> &aa, map<char, vector<int>> &bb, int d) {
    for (auto &it : aa) {
        auto &v = it.second;
        auto &w = bb[it.first];

        if (v.size() != w.size()) return false;
        for (int i = 0; i < v.size(); i++) {
            if (d < abs(v[i] - w[i])) return false;
        }
    }

    return true;
}

void solve() {
    int d;
    string a, b;
    cin >> d >> a >> b;

    if (a.size() != b.size()) {
        cout << "X\n";
        return;
    }
    map<char, vector<int>> aa, bb;
    for (int i = 0; i < a.size(); i++) {
        aa[a[i]].push_back(i);
        bb[b[i]].push_back(i);
    }
    for (auto &it : aa) {
        auto &v = it.second;
        sort(v.begin(), v.end());
    }
    for (auto &it : bb) {
        auto &v = it.second;
        sort(v.begin(), v.end());
    }

    if (ok(aa, bb, d)) cout << "O\n";
    else cout << "X\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
