// https://algospot.com/judge/problem/read/CHILDRENDAY
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

struct T {
    T(int r_, int v_ = 0, string s_ = "") : r(r_), v(v_) { if (!s_.empty()) s.append(s_); }
    int r;
    int v; // n + m <= v ?
    string s;
};

int n, m;
vector<int> num;
bool visit[10000];

void input() {
    string s;
    cin >> s >> n >> m;
    num.clear();
    for (char c : s) {
        num.push_back(c-'0');
    }
    sort(num.begin(), num.end());
    memset(visit, 0, sizeof(visit));
}

void solve() {
    queue<T> Q;
    Q.push(T(0));

    while (!Q.empty()) {
        T now = Q.front(); Q.pop();
        if (n + m <= now.v && now.r == m) {
            cout << now.s << endl;
            return;
        }

        if (!visit[now.r]) {
            if (n + m <= now.v) visit[now.r] = true; // visit
            if (now.v < n + m) now.v *= 10;

            for (int x : num) {
                if (now.v == 0 && x == 0) continue;
                string ss(now.s); ss.push_back('0' + x);
                Q.push(T((now.r*10 + x) % n, now.v + x, ss));
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {input(); solve();}
    return 0;
}
