// http://algospot.com/judge/problem/read/STARFORCE
#include <cstdio>
#include <iostream>

using namespace std;

int n, m, s, best;
int in[200];
int pre[200][200]; // pre processed : or

void input() {
    scanf("%d %d", &n, &m);
    int i, j;
    for (i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }

    for (i = 0; i < n; i++) {
        pre[i][i] = in[i];
        for (j = i + 1; j < n; j++) {
            pre[i][j] = pre[i][j-1] | in[j];
        }
    }
}

bool possible(int all, int start, int remain) {

    if (remain == 0) return true;

    for (int i = start; i <= n - remain; i++) {
        if ((all & pre[start][i]) == all) {
            return possible(all, i+1, remain-1);
        }
    }
    return false;
}

int next(int v) {
    unsigned int t = (v | (v - 1)) + 1;  
    return t | ((((t & -t) / (v & -v)) >> 1) - 1);
}

void solve() {
    int now = 0xFFFF;

    while (now > 0) {
        if (possible(now, 0, m)) break;
        now = next(now) & 0xFFFF;
    }
    printf("%d\n", __builtin_popcount(now));
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
