// https://www.facebook.com/hackercup/problem/1424196571244550/
// Facebook Hacker Cup 2016 Round 1
// Boomerang Tournament
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n;
int in[16][16];
int memo[16][1<<16];

void input() {
    cin >> n;
    for (int r = 0; r < n ; r++) {
        for (int c = 0; c < n ; c++) {
            cin >> in[r][c];
        }
    }
}

int next(int v) {
    unsigned int t = (v | (v - 1)) + 1;  
    return (int)(t | ((((t & -t) / (v & -v)) >> 1) - 1));
}

int win(int i, int flag) {
    int &result = memo[i][flag];
    if ((1<<i) & flag) return result;

    int temp = flag;
    while (temp) {
        int index = __builtin_ctz(temp);
        if (memo[index][flag] && in[i][index]) {
            result = 1;
            break;
        }
        temp &= temp - 1;
    }
    return result;
}

void set_each(int a, int b) {
    int index = a | b;
    for (int i = 0; i < n; i++) {
        if (memo[i][index] == 1 || !(index & (1<<i))) continue;
        if (win(i, a) && win(i, b)) {
            memo[i][index] = 1;
        }
    }
}

int calc_best() {
    memset(memo, 0, sizeof(memo));

    const int limit = 1 << n;
    for (int r = 0; r < n ; r++) {
        memo[r][1<<r] = 1; // itself
    }

    for (int num = 1; num < n; num <<= 1) { // for (1, 2, 4, 8, 16)
        vector<int> v;
        int flag = (1 << num) - 1;
        while (flag < limit) {
            v.push_back(flag);
            flag = next(flag);
        }

        for (int a : v) {
            for (int b : v) {
                if (a <= b) continue; // only b < a
                if (a & b) continue;
                set_each(a, b);
            }
        }
    }
    return 0;
}

int worst(int x) {
    for (int i = 0; i < n; i++) {
        if (i != x && in[x][i] == 0) return ((n >> 1) + 1);
    }
    return 1;
}

int best(int me) {
    const int rank [] = {1, 2, 3, 5, 9};
    const int limit = 1 << n;
    int i(0), num(n);
    for (; 0 < num; num >>= 1, i++) {
        int flag = (1 << num) - 1;
        while (flag < limit) {
            if (flag & (1<<me) && memo[me][flag]) return rank[i];
            flag = next(flag);
        }
    }

    return rank[i];
}

void solve() {
    calc_best();
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", best(i), worst(i));
    }
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        input();
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}

