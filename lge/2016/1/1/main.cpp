// 가계도
#include <iostream>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

int n;
int in[50001][2];
vector<int> v[50001];
bool visit[50001] = { false, };

void clear() {
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i <= 50000; i++) v[i].clear();
}

void solve() {
    cin >> n; n--;

    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> in[i][0] >> in[i][1];
        v[in[i][0]].push_back(in[i][1]);
    }

    for (int i = 0; i < n; i++) { s.insert(in[i][0]); }
    for (int i = 0; i < n; i++) { s.erase(in[i][1]); }

    queue<pair<int, int>> Q; // id - depth
    Q.push(make_pair(*s.begin(), 1));

    int r = 1;
    while (!Q.empty()) {
        auto x = Q.front(); Q.pop();
        int id = x.first;
        int depth = x.second;
        if (visit[id]) continue;
        visit[id] = true;

        for (int i : v[id]) {
            Q.push(make_pair(i, depth+1));
        }
        if (Q.empty()) {
            cout << depth << endl;
        }
    }

    clear();
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
