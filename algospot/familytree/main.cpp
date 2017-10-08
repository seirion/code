// http://algospot.com/judge/problem/read/FAMILYTREE
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n, query;
vector<vector<int>> c; // child
vector<vector<int>> p; // parent
int d[100001]; // depth

void input() {
    scanf("%d %d", &n, &query);
    c.resize(n);
    p.resize(n);

    for (int i = 1; i < n; i++) {
        int x; scanf("%d", &x);
        c[x].push_back(i);
    }
}

void build() {
    d[0] = 0;
    queue<int> q;
    q.push(0); // root
    while (!q.empty()) { // BFS
        int now = q.front(); q.pop();
        int &depth = d[now];

        for (int child : c[now]) {
            d[child] = depth+1;

            int pp = now;
            int index = 0;
            while (true) {
                p[child].push_back(pp);
                if (p[pp].size() <= index) break;
                pp = p[pp][index++];
            }

            q.push(child);
        }
    }
}

int climb(int a, int jump) {
    while (0 < jump) {
        int j = __builtin_ctz(jump);
        jump = jump & (jump - 1);
        a = p[a][j];
    }
    return a;
}

int lcm(int a, int b) {
    if (d[a] < d[b]) {
        b = climb(b, d[b] - d[a]);
    } else {
        a = climb(a, d[a] - d[b]);
    }

    if (a == b) return a;

    int mi(0), ma(d[a]);

    while (mi < ma) {
        int mid = (mi + ma) / 2;
        int x = climb(a, d[a] - mid);
        int y = climb(b, d[b] - mid);

        if (x == y) mi = mid + 1;
        else ma = mid;
    }

    return climb(a, d[a] - ma + 1); 
}

void solve() {
    build();
    while (query--) {
        int a, b; scanf("%d %d", &a, &b);
        int common = lcm(a, b);
        printf("%d\n", d[a] + d[b] - d[common] * 2);
    }
}

void clear() {
    c.clear();
    p.clear();
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {input(); solve(); clear();}
    return 0;
}
