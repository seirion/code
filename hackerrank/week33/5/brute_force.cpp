#include <iostream>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

int n, m, q;
int a, b, c;
vector<set<int>> v;
bool visit[100001] = {false, };

bool go(int now) {
    visit[now] = true;
    for (int x : v[now]) {
        if (x == b) {
            if (visit[c]) return true;
            else continue;
        }
        if (visit[x]) continue;

        if (go(x)) return true;
    }
    visit[now] = false;
    return false;
}

bool go1(int now) {
    if (a != c && b != c) visit[now] = true;
    for (int x : v[now]) {
        if (a == b) v[x].erase(now);
        if (go(x)) return true;
        if (a == b) v[x].insert(now);
    }
    visit[now] = false;
    return false;
}

int main() {
    cin >> n >> m >> q;
    v.resize(n+1);
    while (m--) {
        int x, y; cin >> x >> y;
        v[x].insert(y);
        v[y].insert(x);
    }

    while (q--) {
        cin >> a >> b >> c;
        memset(visit, 0, sizeof(visit));
        if (a == b && b == c) cout << "YES" << endl;
        else if (go1(a)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
