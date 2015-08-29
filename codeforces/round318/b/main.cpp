// codeforces round318
// http://codeforces.com/contest/574/problem/B
#include <iostream>
#include <set>

using namespace std;

int n, m;
set<int> in[4001];

void solve() {
    int mini = 0x7FFFFFFF;
    for (int i = 1; i <= n; i++) {
        if (in[i].size() < 2) continue; 
        for (auto a : in[i]) {
            for (auto b : in[i]) {
                if (a == b) continue;
                if (in[a].find(b) != in[a].end()) {
                    int recognition = in[i].size() + in[a].size() + in[b].size() - 6;
                    mini = min(mini, recognition);
                }
            }
        }
    }

    if (mini == 0x7FFFFFFF) mini = -1;
    cout << mini << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        in[a].insert(b);
        in[b].insert(a);
    }
    solve();
    return 0;
}
