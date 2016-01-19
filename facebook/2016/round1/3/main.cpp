// https://www.facebook.com/hackercup/problem/512731402225321/
// Facebook Hacker Cup 2016 Round 1
// Yachtzee
#include <iostream>
#include <cstdio>

using namespace std;

int n;
long long a, b;
long long in[100001] = {0, };

void input() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
        in[i] += in[i-1];
    }
}

void solve(int k) {
    double expect = 0.0;

    // 1. body
    long long segment = in[n];
    long long end = (b / segment) * segment;
    long long begin = (a + segment - 1) / segment * segment;
    long long num = (begin < end) ? (end - begin) / segment : 0;

    if (num > 0) {
        for (int i = 1; i <= n; i++) {
            int line = in[i] - in[i-1];
            expect += line / 2.0 * line * num;
        }
    }

    // 2. from
    if (a != begin) {
        long long now = a % segment;
        int i;
        for (i = 1; i <= n; i++) {
            if (now < in[i]) { // include
                int line = now - in[i-1];
                expect -= line / 2.0 * line;
                break;
            }

            if (b < in[i]) {
                break;
            }
        }

        for (; i <= n; i++) {
            if (b < in[i]) {
                int line = b - in[i-1];
                expect += line / 2.0 * line;
                break;
            }
            int line = in[i] - in[i-1];
            expect += line / 2.0 * line;
        }
    }

    // 3. end
    if (0 < num && b != end) {
        long long limit = b % segment;
        int i;
        for (i = 1; i <= n; i++) {
            if (limit < in[i]) {
                int line = limit - in[i-1];
                expect += line / 2.0 * line;
                break;
            }
            else {
                int line = in[i] - in[i-1];
                expect += line / 2.0 * line;
            }
        }
    }

    printf("Case #%d: %.10f\n", k, expect / (b - a));
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        input();
        solve(i);
    }
    return 0;
}
