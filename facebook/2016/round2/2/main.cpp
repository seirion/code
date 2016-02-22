// Facebook Hacker Cup 2016 Round 2
// Carnival Coins
// https://www.facebook.com/hackercup/problem/1627951250755660/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int n, k;
double p;
double dp[3001][3001];

void input() {
    cin >> n >> k >> p;
}

void calc_dp() { // n * n
    memset(dp, 0, sizeof(dp));
    dp[1][1] = p;

    for (int r = 2; r <= n; r++) {
        dp[r][1] = dp[r-1][1] * r / (r-1) * (1-p);
        for (int c = 2; c <= r; c++) {
            dp[r][c] = dp[r][c-1] * (r-c+1) / c * p / (1-p);
        }
    }

#if 0
    printf("=========\n");
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= r; c++) {
            printf("%.8f   ", dp[r][c]);
        }
        printf("\n");
    }
    printf("=========\n\n");
#endif
}

void solve(int cases) {
    calc_dp();

    double best = 0.0;
    int limit = n / k;

    for (int num = 1; num <= limit; num++) {
        double result = 0.0;
        vector<int> v(num, n/num);
        int r = n % num;
        for (int i = 0; i < r; i++) v[i]++;

        for (int x : v) {
            for (int i = k; i <= x; i++) {
                result += dp[x][i];
                //printf(": %d, %d (%f)\n", x, i, dp[x][i]);
            }
        }

        //printf(":::::::: %f\n", result);
        best = max(best, result);
    }


    printf("Case #%d: %.9f\n", cases, best);
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        input();
        solve(i);
    }

    return 0;
}
