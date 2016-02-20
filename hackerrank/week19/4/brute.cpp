// https://www.hackerrank.com/contests/w19/challenges/coolguy-and-two-subsequences
// Coolguy and Two Subsequences
#include <iostream>

using namespace std;

const int MOD = 1000000007;

int n;
int in[200000];

int f(int a, int b) {
    int mini = 0x7FFFFFFF;
    for (int i = a; i <= b; i++) {
        mini = min(mini, in[i]);
    }
    return mini;
}

void solve() {
    int res = 0;
    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            for (int c = b+1; c < n; c++) {
                for (int d = c; d < n; d++) {
                    res += min(f(a,b), f(c,d));
                }
            }
        }
    }

    cout << res << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];
    solve();
    return 0;
}
