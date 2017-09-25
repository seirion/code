#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class T { public:
    T(int p_, int cost_) : p(p_), cost(cost_) {}
    int p, cost; // position, cost
    bool operator <(const T& t) const { return p < t.p; }
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
    set<T> v;
    v.insert(T(1, 0));

    for (int d = 0; d < day; d++) {
        set<T> temp;
        for (const T &t : v) {
            int from = t.p;
            for (auto &to : in[from]) {
                auto &vv = to.second;
                int size = vv.size();
                if (size != 0 && vv[d % size] != 0) {
                    
                    T node(to.first, t.cost + vv[d % size]);
                    auto it = temp.find(node);
                    if (it != temp.end()) {
                        node.cost = min(node.cost, it->cost);
                        temp.erase(it);
                    }
                    temp.insert(node);
                }
            }
        }
        v.swap(temp);
    }

    int best = 0x7FFFFFFF;
    for (const T &t : v) {
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

