#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int n, k;
double p;

double comb[3001][3001] = {0, };

void calc_comb() {
    comb[0][0] = 1;
    for (int r = 1; r <= 3000; r++) {
        comb[r][0] = 1;
        for (int c = 1; c <= 3000; c++) {
            comb[r][c] = comb[r-1][c-1] + comb[r-1][c];
        }
    }
}

void input() {
    cin >> n >> k >> p;
}

void solve(int cases) {

    double best = 0.0;
    int x = n / k;

    for (int mm = 1; mm <= x; mm++) {
        double result = 0.0;
        vector<int> v(mm, n/mm);
        int r = n % mm;
        for (int i = 0; i < r; i++) v[i]++;

        for (int num : v) {
            for (int i = k; i <= num; i++) {
                result += comb[num][i] * pow(p, i) * pow(1-p, num-i);
            }
        }

        best = max(best, result);
    }


    printf("Case #%d: %.10f\n", cases, best);
}

int main() {
    calc_comb();

    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        input();
        solve(i);
    }

    return 0;
}
