// codeforces round318
// http://codeforces.com/contest/574/problem/D
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> in;

void solve() {
    in[0] = 1;
    for (int i = 1; i < n; i++) {
        if (in[i-1] < in[i]) {
            in[i] = in[i-1] + 1;
        }
    }

    in[n-1] = 1;
    for (int i = n-2; i >= 0; i--) {
        if (in[i+1] < in[i]) {
            in[i] = in[i+1] + 1;
        }
    }

    cout << *max_element(in.begin(), in.end()) << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        in.push_back(x);
    }
    solve();

    return 0;
}
