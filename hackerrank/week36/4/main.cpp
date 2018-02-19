#include <iostream>
#include <cstdio>
#include <map>
#include <climits>

using namespace std;

int n, t;
int tall[100000];
int price[100000];

void solve() {
    map<int, long long> m, temp;
    m[t] = 0;
    for (int i = 0; i < n; i++) {

        for (auto &x : m) {
            // passing baton
            long long cc = x.second + abs(x.first - tall[i]) + price[i];

            int diff = x.first - tall[i];
            if (tall[i] < x.first /*smaller*/ && 0 < price[i]) {
            } else {
                auto it = temp.find(tall[i]);
                if (it == temp.end()) temp[tall[i]] = cc;
                else if (cc < it->second) it->second = cc;
            }

            if (tall[i] <= x.first) { // not passing
                auto it = temp.find(x.first);
                if (it == temp.end()) temp[x.first] = x.second;
                else if (x.second < it->second) it->second = x.second;
            }
        }

        m.clear();
        temp.swap(m);
    }

    long long best = LLONG_MAX;
    for (auto x : m) {
        best = min(best, x.second);
    }
    cout << best + n + 1 << endl;
}

int main() {
    cin >> n >> t;
    n--;
    for (int i = 0; i < n; i++) scanf("%d", &tall[i]);
    for (int i = 0; i < n; i++) scanf("%d", &price[i]);
    solve();
    return 0;
}
