// http://algospot.com/judge/problem/read/JUMP
#include <cstdio>

using namespace std;

typedef unsigned long long uint64;

uint64 out[1001];

void pre() {
    uint64 multi = 2;
    uint64 jump = 2;

    out[0] = 1;
    for (uint64 i = 1; i <= 1000; i++, multi += jump, jump++) {
        out[i] = multi * multi;

        //printf("%d (%d) %llu\n", i, multi, out[i]);
    }
}

void solve() {
    int n;
    scanf("%d", &n);
    printf("%llu\n", out[n] % 20130728LLU);
}

int main() {
    pre();
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) { solve();}
    return 0;
}
