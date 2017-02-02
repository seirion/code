// https://www.facebook.com/hackercup/problem/300438463685411/
// Facebook Hacker Cup 2016 Round 1
// Manic Moving
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

const int INF = 0x7f7f7f7f;

class Line { public:
    Line(int t, int c) : to(t), cost(c) {}
    int to, cost;
    bool operator <(const Line& l) const { return to < l.to; }
};

int n, m, k;
int dist [5000][5000];
set<Line> line[5000];
int sd[5000][2];
int length_to [5000][5000]; // contains shortest distances


class Node { public:
    Node(int i) : index(i) {}
    int index;
    bool operator <(const Node& l) const {
        return (length_to[index] == length_to[l.index]) ? index < l.index :
            length_to[index] < length_to[l.index];
    }
};

void clear() {
    memset(dist, 0x7F, sizeof(dist));
    memset(length_to, 0x7F, sizeof(length_to));
    for (int i = 0; i < 5000; i++) line[i].clear();
}

void input() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, x; cin >> a >> b >> x;
        a--; b--; // 0-based index

        if (dist[a][b] <= x) continue;
        dist[a][b] = dist[b][a] = x;
        length_to[a][b] = length_to[b][a] = x;

        line[a].insert(Line(b, x));
        line[b].insert(Line(a, x));
    }

    for (int i = 0; i < k; i++) {
        cin >> sd[i][0] >> sd[i][1];
        sd[i][0]--; sd[i][1]--; // 0-based index
    }
}

void dijkstra() {
    for (int i = 0; i < n; i++) {
        length_to[i][i] = 0;

        set<Node> Q;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] != INF) {
                Q.insert(j);
            }
        }

        while (!Q.empty()) {
            Node node = *Q.begin(); Q.erase(Q.begin());

            auto it = line[node.index].begin();
            for (; it != line[node.index].end(); it++) {
                int len = length_to[i][node.index] + dist[node.index][it->to];
                if (length_to[i][it->to] > len) {
                    length_to[i][it->to] = len;
                    Q.erase(Node(it->to));
                    length_to[i][it->to] = len;
                    Q.insert(Node(it->to));
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << length_to[i][j] <<  " ";
        }
        cout << endl;
    }
}

void solve(int k) {
    dijkstra();
    //printf("Case #%d: %.10f\n", k, expect / (b - a));
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        clear();
        input();
        solve(i);
    }
    return 0;
}
