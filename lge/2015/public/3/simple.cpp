// LGE codejam 2015
// 3.
#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <map>

using namespace std;

int n, m;
int in[20000][2];
int best;

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> in[i][0] >> in[i][1];
    }
}

int point(vector<int> &v) {
    map<int, int> mm;
    for (int i = 0; i < v.size(); i++) {
        mm[v[i]] = i;
    }
    int total(0);
    for (int i = 0; i < m; i++) {
        total += abs(mm[in[i][0]] - mm[in[i][1]]);
    }
    return total;
}

void calc(vector<int> &v, deque<int> &remain) {
    if (remain.empty()) {
        best = min(best, point(v));
        return;
    }

    v.push_back(remain.front());
    remain.pop_front();
    calc(v, remain);
    remain.push_front(v.back());
    v.pop_back();

    v.push_back(remain.back());
    remain.pop_back();
    calc(v, remain);
    remain.push_back(v.back());
    v.pop_back();
}

void solve() {
    best = 0x7FFFFFFF;
    vector<int> v;
    deque<int> remain;
    for (int i = 1; i <= n; i++) remain.push_back(i);

    calc(v, remain);
    cout << best << endl;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        input();
        solve();
    }
    return 0;
}
