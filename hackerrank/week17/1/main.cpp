// https://www.hackerrank.com/contests/w17/challenges/find-the-robot
// Find the Robot
#include <iostream>

using namespace std;

long long sum(int init, int rate, int n) {
    return n * (2*init + (n-1) * rate) / 2;
}

void solve() {
    int n; cin >> n;
    long long x(0), y(0);

    long long k;
    k = (n+3) / 4;
    x += sum(1, 4, k);
    k = (n+2) / 4;
    y += sum(2, 4, k);
    k = (n+1) / 4;
    x += sum(-3, -4, k);
    k = (n+0) / 4;
    y += sum(-4, -4, k);

    cout << x << " " << y << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

