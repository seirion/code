// https://www.hackerrank.com/contests/w19/challenges/two-robots
// Two Robots
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

class Node { public:
    Node(int _a = -1, int _b = -1) : a(_a), b(_b) {}
    int a, b;
    bool operator <(const Node &n) const {
        return (a == n.a ? b < n.b : a < n.a);
    }
};

int m, n;
int in[1000][2];
map<Node, int> mm;

void input() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i][0] >> in[i][1];
    }
}

void solve() {
    mm[Node(0, 0)] = 0;

    for (int i = 0; i < n; i++) {
        map<Node, int> temp;
        for (auto &x: mm) {
            const int &a = x.first.a;
            const int &b = x.first.b;
            const int &dist = x.second;

            const int &from = in[i][0];
            const int &to = in[i][1];

            int dist1 = (a == 0 ? 0 : abs(from - a)) + abs(to - from) + dist;
            int dist2 = (b == 0 ? 0 : abs(from - b)) + abs(to - from) + dist;

            Node node;
            // move a
                if (to < b) { node.a = to; node.b = b;}
                else { node.a = b; node.b = to; }
                auto it = temp.find(node);
                if (it == temp.end()) {
                    temp[node] = dist1;
                }
                else {
                    if (dist1 < it->second) it->second = dist1;
                }

            // move b
                if (to < a) { node.a = to; node.b = a;}
                else { node.a = a; node.b = to; }
                auto it2 = temp.find(node);
                if (it2 == temp.end()) {
                    temp[node] = dist2;
                }
                else {
                    if (dist2 < it2->second) it2->second = dist2;
                }
        }
        mm.swap(temp);
    }

    int best = 0x00FFFFFF;
    for (auto &x : mm) {
        best = min(best, x.second);
    }
    cout << best << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}
