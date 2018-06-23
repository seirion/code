#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <functional>

using namespace std;

class T { public :
    T(int i_, int v_) : i(i_),  v(v_) {}
    int i, v;
    bool operator >(const T &o) const {
        return make_pair(v, i) > make_pair(o.v, o.i);
    }
};

int n, k, m;
int mini[10002];
map<int, map<int, int>> in;

void input() {
    cin >> n >> k >> m;
    while (m--) {
        int x, y, v; cin >> x >> y >> v;
        in[x][y] = in[y][x] = v;
    }
    memset(mini, 0x7f, sizeof(mini));
}

// dijkstra
void solve() {
    priority_queue<T, vector<T>, greater<T>> q;
    q.push(T(1, 0));

    while (!q.empty()) {
        T now = q.top(); q.pop();
        int &from = now.i;
        int &sofar = now.v;
        //cout << " - " << from << " " << sofar << endl;
        mini[now.i] = sofar;
        if (now.i == n) {
            cout << sofar << endl;
            break;
        }


        for (const auto& it : in[now.i]) {
            int to = it.first;
            int cost = it.second;
            //cout << "     :: " << to << " " << cost << endl;

            int v = sofar;
            v += cost;
            int r = v % (2*k); // temporary

            if (to != n) {
                if (r < k) { // safe
                } else { // need to wait
                    v += (2*k - r); // v 는 2k 의 배수
                }
            }

            if (v < mini[to]) {
                mini[to] = v;
                q.push(T(to, v));
            }
        }
    }
    //cout << mini[n] << endl;
}

int main() {
    input();
    solve();
    return 0;
}
