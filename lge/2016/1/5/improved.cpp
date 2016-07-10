// 뱀 발전기
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int p[2000];
int m[2000]; // male-female
int memo[2000][2000];
vector<int> f;

void input() {
    f.clear();

    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) {
        cin >> m[i];
        if (m[i]) f.push_back(i);
    }

    memset(memo, 0xFF, sizeof(memo));
    for (int i = 0; i < n; i++) memo[i][i] = 0;
}

int calc(int begin, int end) { // [begin, end]
    if (end <= begin) return 0;

    int &r = memo[begin][end];
    if (r != -1) return r;
    r = max(0, calc(begin+1, end));

    if (m[begin]) {
        for (int i = begin+1; i <= end; i++) {
            if (m[begin]^m[i]) r = max(r, p[begin]*p[i] + calc(begin+1, i-1) + calc(i+1, end));
        }
    }
    else {
        auto it = lower_bound(f.begin(), f.end(), begin);
        for (; it != f.end() && *it <= end; it++) {
            int &i = *it;
            r = max(r, p[begin]*p[i] + calc(begin+1, i-1) + calc(i+1, end));
        }
    }

    return r;
}

void solve() {
    cout << calc(0, n-1) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) { input(); solve(); }
    return 0;
}
