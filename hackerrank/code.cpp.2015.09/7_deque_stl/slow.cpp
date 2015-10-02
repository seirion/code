// https://www.hackerrank.com/contests/code-cpp-september-2015/challenges/deque-stl
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void solve() {
    int i, n, k;
    deque<int> Q;

    cin >> n >> k;
    k--;
    for (i = 0; i < k; i++) {
        int x; cin >> x;
        Q.push_back(x);
    }

    for (; i < n; i++) {
        int x; cin >> x;
        Q.push_back(x);
        cout << *max_element(Q.begin(), Q.end()) << " ";
        Q.pop_front();
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
