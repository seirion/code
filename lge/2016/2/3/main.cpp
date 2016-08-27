// 접선 (Contact)
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <functional>

using namespace std;

struct Line {
    Line(int t, int d_) : to(t), d(d_) {}
    int to, d; // to, distance
    bool operator <(const Line &l) const { return to < l.to; }
};

int n, line_num, query;
set<int> path[501]; // path from
int dist[501];
set<Line> in[501];
pair<int, int> mini; // solution

struct T {
    T(int i_ = 0) : i(i_) {}
    int i;
    bool operator >(const T &t) const {
        return dist[i] == dist[t.i] ? i > t.i : dist[i] > dist[t.i];
    }
};

void input() {
    cin >> n >> line_num >> query;
    for (int i = 0; i < line_num; i++) {
        int a, b, c; cin >> a >> b >> c;
        in[a].insert(Line(b, c));
        in[b].insert(Line(a, c));
    }
}

int dist_to(int from, int to) {
    auto it = in[from].find(Line(to, 0));
    return it->d;
}

void find_min(int begin, int end, int len) {
    for (int to : path[end]) {
        if (dist[to] * 2 == len) {
            mini = min(mini, make_pair(to, to));
        }
        else if (dist[to] * 2 < len || to == begin) {
            int a = min(to, end);
            int b = max(to, end);
            mini = min(mini, make_pair(a, b));
        }
        else {
            find_min(begin, to, len);
        }
    }
}

void dijkstra(int begin, int end) {
    memset(dist, 0x7F, sizeof(dist));

    priority_queue<T, vector<T>, greater<T>> Q;
    Q.push(T(begin));
    dist[begin] = 0;

    while (!Q.empty()) {
        T now = Q.top(); Q.pop();
        if (now.i == end) {
            continue;
        }

        for (auto &it : in[now.i]) {
            int len = dist[now.i] + dist_to(now.i, it.to);
            if (len == dist[it.to]) {
                path[it.to].insert(now.i);
            }
            else if (len < dist[it.to]) {
                dist[it.to] = len;
                path[it.to].clear();
                path[it.to].insert(now.i);
                Q.push(T(it.to));
            }
        }
    }

    mini = make_pair(n+1, n+1);
    find_min(begin, end, dist[end]);
    cout << mini.first << " " << mini.second << endl;
}

void clear() {
    for (int i = 1; i <= n; i++) { path[i].clear(); }
}

void solve() {
    for (int i = 0; i < query; i++) {
        int a, b; cin >> a >> b;
        dijkstra(a, b);
        clear();
    }
    for (int i = 1; i <= n; i++) { in[i].clear(); }
}

int main() {
    int t; cin >> t;
    while (t--) { input(); solve(); }
    return 0;
}
