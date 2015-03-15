// https://www.acmicpc.net/problem/10736
// Coder's High 2015 Side Contest
// XOR삼형제
#include <cstdio>
#include <set>

using namespace std;

void print(const set<int> &out) {
    printf("%d\n", out.size());
    for (int i : out) {
        printf("%d ", i);
    }
    printf("\n");
}

void solve(int n) {
    if (n == 1) {
        printf("1\n1\n");
        return;
    }

    int c = 32 - __builtin_clz(n);

    set<int> out;

    int from = 1 << (c - 1);
    int to = min(n, (from | (from >> 1)) - 1);

    for (int i = from; i <= to; i++) {
        out.insert(i);
    }

    to = from;
    from = from >> 1;
    for (int i = from; i < to; i++) {
        out.insert(i);
    }

    print(out);
}

int main() {
    int c, n;
    scanf("%d", &c);
    while (c--) {
        scanf("%d", &n);
        solve(n);
    }
    return 0;
}
