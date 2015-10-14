// codeforces round325
// http://codeforces.com/contest/586/problem/C
#include <iostream>
#include <vector>
#include <list>

using namespace std;
typedef long long int64;

class Node { public:
    Node(int i_, int v_, int d_, int64 p_) : i(i_), v(v_), d(d_), p(p_) {}
    int i, v, d;
    int64 p;
};

list<Node> Q;
int n;

void input() {
    cin >> n;
    int v, d;
    int64 p;
    for (int i = 0; i < n; i++) {
        cin >> v >> d >> p;
        Q.push_back(Node(i, v, d, p));
    }
}

void cry(int v) {
    auto it = Q.begin();
    while (it != Q.end() && v > 0) {
        it->p -= v--;
        it++;
    }
}

void run_away() {
    int64 cry = 0;
    auto it = Q.begin();
    while (it != Q.end()) {
        it->p -= cry;
        if (it->p < 0) {
            cry += it->d;
            it = Q.erase(it);
        }
        else it++;
    }
}

void solve() {
    vector<int> result;

    while (!Q.empty()) {
        Node n = *Q.begin();
        Q.erase(Q.begin());
        result.push_back(n.i);

        cry(n.v);
        run_away();
    }

    cout << result.size() << endl;
    for (int x : result) cout << x+1 << " ";
    cout << endl;
}

int main() {
    input();
    solve();
    return 0;
}
