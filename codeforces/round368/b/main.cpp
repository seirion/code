// http://codeforces.com/contest/707/problem/B
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
set<pair<int, int>> s[100001];
vector<int> v;

int main() {
    cin >> n >> m >> k;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        s[a].insert(make_pair(b, c));
        s[b].insert(make_pair(a, c));
    }
    
    while (k--) {
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int r = 0x7FFFFFFF;
    for (int x : v) {
        for (auto p : s[x]) {
            int &to = p.first;
            int &cost = p.second;
            if (!binary_search(v.begin(), v.end(), to)) {
                r = min(r, cost);
            }
        }
    }

    if (r == 0x7FFFFFFF) r = -1;
    cout << r << endl;
    return 0;
}
