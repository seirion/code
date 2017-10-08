// http://algospot.com/judge/problem/read/GALLERY
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n, m;
vector<int> in[1001];
bool visit[1001];
int res;

void input() {
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < 1001; i++) in[i].clear();

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        in[a].push_back(b);
        in[b].push_back(a);
    }
}

const int NOT_COVERED = 0;
const int INSTALLED = 1;
const int COVERED = 2;

int dfs(int now) {
    visit[now] = true;
    bool need_install = false;
    bool covered = false;

    for (int to : in[now]) {
        if (!visit[to]) {
            switch (dfs(to)) {
                case NOT_COVERED:
                    need_install = true;
                    break;
                case INSTALLED:
                    covered = true;
                    break;
            }
        }
    }
    if (need_install) {
        res++;
        return INSTALLED;
    }

    if (covered) return COVERED;
    else return NOT_COVERED;
}

void solve() {
    res = 0;
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            switch (dfs(i)) {
                case NOT_COVERED:
                    res++;
            }
        }
    }
    cout << res << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {input(); solve();}
    return 0;
}
