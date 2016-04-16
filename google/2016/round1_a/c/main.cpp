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
bool check[1000];
int first;
map<int, set<int>> m;

int max_depth(int index) {
    
    auto s = m[index];
    if (s.empty()) return 0;

    int maxi = 0;
    for (auto x : s) {
        maxi = max(maxi, max_depth(x));
    }

    return 1 + maxi;
}

int max_cycles(const set<int> &ss) {
    int best = 0;
    for (auto x : ss) {
        set<int> s(ss);
        int len = 0;
        int first = x;
        int now = x;

        while (true) {
            s.erase(now);
            len++;
            if (in[now] == first) {
                best = max(best, len);
                break;
            }

            auto it = s.find(in[now]);
            if (it != s.end()) now = *it; // exist
            else break;
        }
    }

    return best;
}

void solve() {
    m.clear();
    memset(check, 0, sizeof(check));

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        in[i]--; // make it 0-based index
        m[in[i]].insert(i);
    }

    set<int> s;
    for (int i = 0; i < n; i++) {
        if (i == in[in[i]]) { // BF each other
            s.insert(i); s.insert(in[i]);
            m[i].erase(in[i]);
            m[in[i]].erase(i);
        }
    }

    int sum = s.size();
    for (auto x : s) {
        sum += max_depth(x);
    }


    set<int> ss;
    for (int i = 0; i < n; i++) ss.insert(i);
    for (auto x : s) ss.erase(x);

    sum = max(sum, max_cycles(ss));
    cout << sum << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}

