// https://www.hackerrank.com/contests/w19/challenges/find-the-permutation
// Find the permutation
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

long long n, k;
map<int, set<vector<int>>> m;

void print(const vector<int> &v) {
    for (auto x:v) cout << x << " ";
    cout << endl;
}

void put(const vector<int> &v) {
    int mini = 0x0FFFFFFF;
    for (int i = 1; i < v.size(); i++) {
        mini = min(mini, abs(v[i] - v[i-1]));
    }
    m[mini].insert(v);
}

void solve() {
    cin >> n >> k;
    vector<int> v(n);
    unsigned long long limit = 1;

    for (int i = 0; i < n; i++) {
        v[i] = i+1;
        limit *= v[i];
    }

    for (int i = 0; i < limit; i++) {
        put(v);
        next_permutation(v.begin(), v.end());
    }

    auto it = m.rbegin();
    const auto &s = it->second;
    if (k <= s.size()) {
        auto i = s.begin();
        advance(i, k-1); 
        print(*i);
    }
    else {
        cout << -1 << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
