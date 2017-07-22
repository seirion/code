#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n, q;
map<int, vector<int>> m;
map<pair<int, int>, int> cache;

inline int num(int x) {
    return (x * (x + 1)) >> 1;
}

bool caching(int x, int y) {
    auto it = cache.find(make_pair(x, y));
    if (it != cache.end()) {
        cout << it->second << endl; return true;
    }

    it = cache.find(make_pair(y, x));
    if (it != cache.end()) {
        cout << it->second << endl; return true;
    }
    return false;
}

void query(int x, int y) {
    if (x == y) {
        cout << num(n) << endl;
        return;
    }

    if (caching(x, y)) {
        return;
    }

    auto &xx = m[x];
    auto &yy = m[y];

    vector<int> v;
    vector<bool> vv;
    v.push_back(0);
    vv.push_back(false);

    auto i = xx.begin();
    auto j = yy.begin();

    while (i != xx.end() || j != yy.end()) {
        if (i == xx.end()) {
            v.push_back(*j);
            vv.push_back(false); j++;
        } else if (j == yy.end()) {
            v.push_back(*i);
            vv.push_back(true); i++;
        } else if (*i < *j) {
            v.push_back(*i);
            vv.push_back(true); i++;
        } else {
            v.push_back(*j);
            vv.push_back(false); j++;
        }
    }
    v.push_back(n+1);

    int r = 0;
    for (int k = 1; k < v.size(); k++) {
        r += num(v[k] - v[k-1] - 1);
    }

    int SIZE = v.size();

    for (int a = 1; a + 1 < SIZE; a++) {
        int aa = 0; int bb = 0;
        int left = v[a];
        if (vv[a]) aa++;
        else bb++;

        for (int b = a + 1; b + 1 < SIZE; b++) {

            int right = v[b];

            if (vv[b]) aa++;
            else bb++;

            if (aa == bb) {
                r += (v[a] - v[a-1]) * (v[b+1] - v[b]);
            }
        }

        if (vv[a]) aa--;
        else bb--;
    }

    cache[make_pair(x, y)] = r;
    cout << r << endl;
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        m[x].push_back(i);
    }

    while (q--) {
        int x, y; cin >> x >> y;
        query(x, y);
    }

    return 0;
}
