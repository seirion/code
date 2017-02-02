#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n;
int in[100001];
map<int, vector<int>> m;

map<pair<int, int>, bool> cc; // cache : root, index

int out;

void input() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) cin >> in[i];
}

bool check_sub(int index, int root) {
    auto it = cc.find(make_pair(root, index));
    if (it != cc.end()) {
        return it->second;
    }

    vector<int> &v = m[index];

    const int &prev = in[index];
    for (int i : v) {
        if (i == root) continue;
        if (prev != in[i] || !check_sub(i, index)) {
            cc[make_pair(root, index)] = false;
            return false;
        }
    }

    cc[make_pair(root, index)] = true;
    return true;
}

bool ok(int root) {
    for (int x : m[root]) {
        if (!check_sub(x, root)) return false;
    }
    out = root;
    return true;
}

bool ok() {
    for (int x = 1; x <= n; x++) {
        if (ok(x)) return true;
    }
    return false;
}

void solve() {
    if (ok()) cout << "YES\n" << out << endl;
    else cout << "NO\n";
}

int main() {
    input();
    solve();
    return 0;
}
