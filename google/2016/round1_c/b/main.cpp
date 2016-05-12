// https://code.google.com/codejam/contest/4314486/dashboard#s=p1
// Problem B. Slides!
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n;
long long m;
vector<long long> v;
const char *ZERO = "00000000000000000000000000000000000000000000000000";
const char  *ONE = "11111111111111111111111111111111111111111111111111";

void zero(int i) { cout << (ZERO + 50 - i); }
void  one(int i) { cout <<  (ONE + 50 - i); }

void solve() {
    cin >> n >> m;

    if ((1LL << (n-2)) < m) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << "POSSIBLE\n";
    if ((1LL << (n-2)) == m) {
        for (int r = 1; r < n; r++) {
            zero(r); one(n-r); cout << endl;
        }
        zero(n); cout << endl;
        return;
    }

    for (int r = 1; r < n; r++) {
        zero(r); one(n-r-1);
        cout << (m & (1LL << (r-2)) ? '1' : '0') << endl;
    }
    zero(n); cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}

