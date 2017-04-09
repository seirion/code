// https://code.google.com/codejam/contest/3264486/dashboard#s=p2
// Problem C. Bathroom Stalls
#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

long long n, k;
map<long long, long long, greater<long long>> m; // length of segment

void solve() {
    m.clear();
    cin >> n >> k;
    m[n] = 1;

    while (true) {
        auto it = m.begin();
        long long len = it->first;
        long long num = it->second;

        long long a = len / 2;
        long long b = a - 1 + (len & 1LL);
        if (k <= num) {
            cout << a << " " << b << endl;
            return;
        }

        m[a] += num;
        m[b] += num;
        m.erase(it);
        k -= num;
    }
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}

