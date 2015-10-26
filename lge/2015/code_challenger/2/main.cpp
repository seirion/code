// https://www.lgcodechallenger.com
// problem 2
#include <iostream>
#include <cstring>

using namespace std;

int n, a, b, in[10005];
int memo[10005];

void input() {
    memset(in, 0, sizeof(in));
    memset(memo, 0, sizeof(memo));

    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) cin >> in[i+5];

}

void solve() {
    for (int i = 5; i <= n+5; i++) {
        memo[i] = memo[i-1] + in[i] * a;
        memo[i] = min(memo[i], memo[i-1] + b);
        memo[i] = min(memo[i], memo[i-2] + b);
        memo[i] = min(memo[i], memo[i-3] + b);
        memo[i] = min(memo[i], memo[i-4] + b);
        memo[i] = min(memo[i], memo[i-5] + b);
    }
    cout << memo[n+5] << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}
