// LGE codejam 2015
// 3. ... ...
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> in[20001];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        in[a].push_back(b);
        in[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) sort(in[i].begin(), in[i].end());
}

int common_friends(int a, int b) { // a != b
    std::vector<int> v(max(in[a].size(), in[b].size()));
    auto it = set_intersection(in[a].begin(), in[a].end(), in[b].begin(), in[b].end(), v.begin());
    return it - v.begin();
}

void solve() {
    int best(0);
    for (int a = 1; a <= n; a++) {
        if (in[a].size() <= best) continue;
        for (int b = a+1; b <= n; b++) {
            if (in[b].size() <= best) continue;
            auto it = lower_bound(in[a].begin(), in[a].end(), b);
            if (it != in[a].end() && *it == b) continue;
            best = max(best, common_friends(a, b));
        }
    }
    cout << best << endl;
}

void clear() {
    for (int i = 1; i <= n; i++) in[i].clear();
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        input();
        solve();
        clear();
    } 
    return 0;
}
