// https://code.google.com/codejam/contest/4304486/dashboard#s=p2&a=2
// Problem C. BFFs
#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

int n;
int in[1000];
int best = 0;
int first;
set <int> s;

void aaa(int left, int now, int len) {
    //cout << " --- " << now << "(" << len << ")\n";

    if (in[now] == left || in[now] == first) {
        best = max(best, len);
    }

    int next = in[now];
    auto it = s.find(next);
    if (it != s.end()) {
        s.erase(it);
        aaa(now, next, len+1);
        s.insert(next); // roll-back
    }

    if (in[now] != left) return;

    for (int i = 0; i < n; i++) {
        auto itt = s.find(i);
        if (itt != s.end()) {
            s.erase(itt);
            aaa(now, i, len+1);
            s.insert(i); // roll-back
        }
    }
}

void solve() {
    best = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        in[i]--; // make it 0-based index
    }

    for (int i = 0; i < n; i++) {
        first = i;
        int next = in[i];

        s.clear();
        for (int x = 0; x < n; x++) if (x != i && x != next) s.insert(x);
        aaa(i, next, 2);
    }
    cout << best << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}

