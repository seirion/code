// codeforces round320
// http://codeforces.com/contest/579/problem/B
#include <iostream>
#include <queue>

using namespace std;

class Node { public:
    Node(int v_, int r_, int c_) : v(v_), r(r_), c(c_) {}
    int v, r, c;
    bool operator <(const Node &n) const {
        return v < n.v;
    }
};

int n;
priority_queue<Node> Q;

void input() {
    cin >> n;
    n <<= 1;
    for (int r = 2; r <= n; r++) {
        for (int c = 1; c < r; c++) {
            int x; cin >> x;
            Q.push(Node(x, r, c));
        }
    }
}

void solve() {
    int out[801] = {0, };

    while (!Q.empty()) {
        Node n = Q.top(); Q.pop();
        if (out[n.r] || out[n.c]) continue;
        out[n.r] = n.c;
        out[n.c] = n.r;
    }

    for (int i = 1; i <= n; i++) {
        cout << out[i] << " ";
    }
    cout << endl;
}

int main() {
    input();
    solve();
    return 0;
}
