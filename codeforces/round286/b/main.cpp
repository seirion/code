// http://codeforces.com/contest/505/problem/B
// Problem B
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

bool g[101][101][101];
bool vigit[101][101];

int n, m;
void solve(int from, int to) {
    int i, count(0);

    queue<pair<int, int> > Q;
    for (i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[from][i][j]) {
                Q.push(make_pair<int, int>(i, j));
                vigit[i][j] = true;
            }
        }
    }

    while (!Q.empty()) {
        pair<int, int> p = Q.front();
        Q.pop();

        if (p.first == to) count++;

        int color = p.second;
        for (i = 1; i <= n; i++) {
            if (g[p.first][i][color] && !vigit[i][color]) {
                Q.push(make_pair<int, int>(i, color));
                vigit[i][color] = true;
            }
        }
    } 

    printf("%d\n", count);
}

int main() {
    memset(g, 0, sizeof(bool) * 101 * 101 * 101);
    int i;
    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a][b][c] = true;
        g[b][a][c] = true;
    }

    int k;
    scanf("%d", &k);
    for (i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        memset(vigit, 0, sizeof(bool) * 101 * 101);
        solve(a, b);
    }

    return 0;
}
