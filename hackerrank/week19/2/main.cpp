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
    mm[Node(-1, -1)] = 0;

    for (int i = 0; i < n; i++) {
        map<Node, int> temp;
        for (auto &x: mm) {
            int a = x.first.a;
            int b = x.first.b;
            int dist = x.second;

            const int &from = in[i][0];
            const int &to = in[i][1];

            int dist1 = (a == -1 ? 0 : abs(from - a)) + abs(to - from) + dist;
            int dist2 = (b == -1 ? 0 : abs(from - b)) + abs(to - from) + dist;

            // move a
            {
                Node node(min(to,b), max(to,b));
                if (temp.find(node) == temp.end()) {
                    temp[Node(node)] = dist1;
                }
                else {
                    temp[node] = min(temp[node], dist1);
                }
            }

            // move b
            {
                Node node(min(a, to), max(a, to));
                if (temp.find(node) == temp.end()) {
                    temp[node] = dist2;
                }
                else {
                    temp[node] = min(temp[node], dist2);
                }
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
