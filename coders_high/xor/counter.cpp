// https://www.acmicpc.net/contest/problem/84/6
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int out[101];
int next(int v) {
    unsigned int t = (v | (v - 1)) + 1;
    return t | ((((t & -t) / (v & -v)) >> 1) - 1);
}

vector<int> sel;

bool xor3(const vector<int> &cand, int n) {
    int a = __builtin_ctz(n);
    n &= n - 1;
    int b = __builtin_ctz(n);
    n &= n - 1;
    int c = __builtin_ctz(n);

    return cand[a] ^ cand[b] ^ cand[c];
}

void print_all(vector<int> &cand) {
    for (int a : cand) cout << a << " ";
    cout << endl;
}

bool ok(int n) { // 3개를 뽀는 모든 경우의 수에 대해 검사
    vector<int> cand;
    int now = n;
    while (now) {
        int c = __builtin_ctz(now) + 1;
        now &= now - 1;
        cand.push_back(c);
    }

    int size = cand.size();
    int limit = 1 << size;
    now = 7; // 1 + 2 + 4
    while (now < limit) {
        if (0 == xor3(cand, now)) return false;
        now = next(now);
    }

    print_all(cand);
    return true;
}

int fill(int n) {
    const int all = (1 << n) - 1;
    int now = all;

    while (now) {
        if (ok(now)) break;
        now = next(now) & all;
    }
    return __builtin_popcount(now);
}

void pre() {
    out[0] = 0; out[1] = 1; out[2] = 2; out[3] = 2;
    for (int i = 4; i <= 30; i++) {
        out[i] = fill(i);
    }
}

int main() {
    pre();
    int c, n;
    scanf("%d", c);
    while (c--) {
        scanf("%d", n);
        printf("%d\n", out[n]);
    }
    return 0;
}
