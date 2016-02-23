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

double mylog[3002];

void input() {
    cin >> n >> k >> p;
}

void calc_log() {
    for (int i = 1; i < 3000; i++) mylog[i] = log10(i);
}

// n! / r! / (n-r)! * p^n * q^(n-r)
double calc(int all, int to) {
    double result = 0.0;
    for (int i = 1; i <= all; i++) result += mylog[i];
    for (int i = 1; i <= to; i++) result -= mylog[i];
    for (int i = 1; i <= (all-to); i++) result -= mylog[i];
    result += (to * log10(p));
    result += ((all-to) * log10(1.0-p));

    return pow(10, result);
}

void solve(int cases) {

    double best = 0.0;
    int limit = n / k;

    for (int num = 1; num <= limit; num++) {
        double result = 0.0;
        vector<int> v(num, n/num);
        int r = n % num;
        for (int i = 0; i < r; i++) v[i]++;

        for (int x : v) {
            for (int i = k; i <= x; i++) {
                result += calc(x, i);
            }
        }

        best = max(best, result);
    }


    printf("Case #%d: %.9f\n", cases, best);
}

int main() {
    calc_log();

    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        input();
        solve(i);
    }

    return 0;
}
