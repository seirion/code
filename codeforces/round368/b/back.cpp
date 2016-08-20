#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n, m, k;
set<pair<int, int>> s[100001];
set<int> v;

int main() {
    cin >> n >> m >> k;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        s[a].insert(make_pair(b, c));
        s[b].insert(make_pair(a, c));
    }
    
    while (k--) {
        int a; cin >> a;
        v.insert(a);
    }

    int r = 0x7FFFFFFF;
    for (int x : v) {
        for (auto p : s[x]) {
            int &to = p.first;
            int &cost = p.second;
            if (find(v.begin(), v.end(), to) == v.end()) {
                r = min(r, cost);
            }
        }
    }

    if (r == 0x7FFFFFFF) r = -1;
    cout << r << endl;
    return 0;
}
