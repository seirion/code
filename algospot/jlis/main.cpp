// http://algospot.com/judge/problem/read/JLIS
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, m;
long long in1[101], in2[101];
int memo[101][101];

void input() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &in1[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &in2[i]);
    }
}

int jlis(int index1, int index2) {
    int &ret = memo[index1][index2];
    if (ret != -1) return ret;

    ret = (in1[index1] == in2[index2] ? 1 : 2);
    long long maxi = max(in1[index1], in2[index2]);
    for (int i = index1+1; i <= n; i++) {
        if (maxi < in1[i]) {
            ret = max(ret, jlis(i, index2) + 1);
        }
    }
    for (int i = index2+1; i <= m; i++) {
        if (maxi < in2[i]) {
            ret = max(ret, jlis(index1, i) + 1);
        }
    }
    return ret;
}

void solve() {
    memset(memo, 0xFF, sizeof(int) * 101 * 101); // set -1
    in1[0] = in2[0] = -98765432123456789LL;
    printf("%d\n", jlis(0, 0) - 2);
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
