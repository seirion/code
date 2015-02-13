// http://algospot.com/judge/problem/read/GOODSET
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
bool nn[501];
bool mm[501];

void solve() {
    memset(nn, 0, sizeof(bool) * 501);
    memset(mm, 0, sizeof(bool) * 501);

    int i;
    bool res = true;
    scanf("%d %d\n", &n, &m);
    for (i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        if (num == 0 || num == m) res = false;
        for (int j = 1; j <= num; j++) {
            int t;
            scanf("%d", &t);
            nn[i] = mm[t] = true;
        }
    }

    if (!res) { printf("NO\n"); return; }
    for (i = 1; i <= n; i++) {
        if (!nn[i]) {
            res = false; break;
        }
    }
    if (!res) { printf("NO\n"); return; }

    for (i = 1; i <= m; i++) {
        if (!mm[i]) {
            res = false; break;
        }
    }
    if (!res) { printf("NO\n"); return; }
    printf("YES\n");
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {solve();}
    return 0;
}
