// https://www.hackerrank.com/contests/code-cpp-september-2015/challenges/consecutive-numbers
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool in[10002];

int consecutive (vector<int> &arr) { // longest consecutive numbers
    memset(in, 0, sizeof(in));
    for (auto i : arr) {
        in[i] = true;
    }

    int maxi(0), now(0);
    for (int i = 0; i <= 10000; i++) {
        if (in[i]) {
            now++;
            maxi = max(maxi, now);
        }
        else {
            now = 0;
        }
    }
    return maxi;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << consecutive(v) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
