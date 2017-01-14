// https://www.facebook.com/hackercup/problem/1800890323482794/
// Facebook Hacker Cup 2017 Round 1
// Pie Progress
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
int in[300];
int adding[300];
multiset<pair<int, int>> all; // price, day

void build() {
    int x = 1; int p = 0;
    for (int i = 0; i < 300; i++) {
        adding[i] = x * x - p;
        x++; p += adding[i];
    }
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> in[j];
        sort(in, in + m);

        for (int j = 0; j < m; j++) {
            all.insert(make_pair(in[j] + adding[j], i));
        }
    }
}

void solve(int k) {
    long long result = 0;
    int day = 0;

    while (day < n) {
        auto it = all.begin();
        while (day < it->second) it++; // cannot eat the one from the future

        day++;
        result += it->first;
        all.erase(it);
    }
    printf("Case #%d: %lld\n", k, result);
}

int main() {
    build();
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        all.clear();
        input();
        solve(i);
    }

    return 0;
}
