// http://algospot.com/judge/problem/read/
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

int n;
bool infected[100];
set<int> f[100]; // friend-ship

void input() {
    scanf("%d", &n);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int x; scanf("%d", &x);
            if (x == 1) {
                f[r].insert(c);
            }
        }
    }
}

void go(int a, int b) {
    if (a == b) return;
    infected[a] = infected[b] = true;

    bool new_one = true;
    while (new_one) {
        new_one = false;
        for (int i = 0; i < n; i++) {
            if (infected[i]) continue;
            int count = 0;
            for (int one : f[i]) {
                if (infected[one]) count++;
                if (count >= 2) {
                    infected[i] = true;
                    new_one = true;
                    break;
                }
            }
        }
    }
}

void solve() {
    int q; scanf("%d", &q);
    while (q--) {
        int a, b; scanf("%d %d", &a, &b);
        memset(infected, 0, sizeof(infected));
        go(a-1, b-1);

        int all = 0;
        for (int i = 0; i < n; i++) {
            if (infected[i]) all++;
        }
        printf("%d ", all);
    }
    printf("\n");
}

void clear() {
    for (int i = 0; i < n; i++) f[i].clear();
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {input(); solve(); clear();}
    return 0;
}
