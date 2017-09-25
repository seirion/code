#include <iostream>
#include <vector>
#include <map>

using namespace std;

class T { public:
    T(int p_, int cost_) : p(p_), cost(cost_) {}
    int p, cost; // position, cost
};

int n, day, m;
map<int, map<int, vector<int>>> in;

void input() {
    in.clear();

    cin >> n >> day >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        while (c--) {
            int x; cin >> x;
            in[a][b].push_back(x);
        }
    }
}

void solve() {
    vector<T> v;
    v.push_back(T(1, 0));

    for (int d = 0; d < day; d++) {
        vector<T> temp;
        for (T &t : v) {
            int from = t.p;
            for (auto &to : in[from]) {
                auto &vv = to.second;
                int size = vv.size();
                if (size != 0 && vv[d % size] != 0) {
                    temp.push_back(T(to.first, t.cost + vv[d % size]));
                }
            }
        }
        v.swap(temp);
    }

    int best = 0x7FFFFFFF;
    for (T &t : v) {
        if (t.p == 1) {
            best = min(best, t.cost);
        }
    }
    if (best == 0x7FFFFFFF) best = -1;
    cout << best << endl;
}

int main() {
    int t; cin >> t;
    while (t--) { input(); solve(); }
    return 0;
}

