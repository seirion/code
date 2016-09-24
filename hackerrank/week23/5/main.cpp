// https://www.hackerrank.com/contests/w23/challenges/gravity-1
// Gravity Tree
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class T { public:
    T(int p_ = 0, int d_ = 0) : p(p_), d(d_) {}
    int p, d; // parent, depth
};

int n, query;
T in[100001];
vector<int> v[100001];


int lowest_common_ancestor(int a, int b) {
    int min_depth = min(in[a].d, in[b].d);
    while (min_depth < in[a].d) a = in[a].p;
    while (min_depth < in[b].d) b = in[b].p;

    while (a != b) {
        a = in[a].p;
        b = in[b].p;
    }
    return a;
}

bool direct_line(int a, int b) {
    int c = lowest_common_ancestor(a, b);
    return c == a || c == b;
}

long long under(int x, int plus, int except) {
    long long r = 0;
    const int d = in[x].d;

    queue<T> q;
    q.push(T(x, in[x].d)); // p : index, d : depth
    while (!q.empty()) {
        int now = q.front().p;
        int dd = q.front().d;
        q.pop();

        if (now == except) continue;

        r += (dd - d + plus) * (dd - d + plus);
        for (int k : v[now]) q.push(T(k, in[k].d));
    }
    return r;
}

void build() {
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int now = q.front(); q.pop();
        in[now].d = in[in[now].p].d + 1;
        for (int x : v[now]) q.push(x);
    }
}

void solve(int a, int b) {
    if (direct_line(a, b) && in[b].d < in[a].d) {
        long long r = 0;
        int now(a), prev(-1), d(0);
        while (b <= now) {
            r += under(now, d++, prev);
            prev = now;
            now = in[now].p;
        }
        cout << r << endl;
    }
    else {
        int c = lowest_common_ancestor(a, b);
        int dist = in[a].d + in[b].d - in[c].d * 2;
        cout << under(b, dist, -1) << endl;
    }
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> in[i].p;
        //in[i].d = in[in[i].p].d + 1;
        v[in[i].p].push_back(i);
    }
    build();
    cin >> query;
    while (query--) {
        int a, b; cin >> a >> b;
        solve(a, b);
    }

    return 0;
}
