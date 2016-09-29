//
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, k;
vector<int> in;

void input() {
    cin >> n >> k;
    in.resize(n);
    for (int i = 0; i < n; i++) cin >> in[i];
}

void solve() {
    sort(in.begin(), in.end());

    set<int> s;
    for (int i = 0; i < n; i++) {
        if (k < in[i]) break;

        set<int> temp;
        temp.insert(in[i]);
        for (int x : s) {
            temp.insert(x);
            if (x + in[i] <= k) temp.insert(x+in[i]);
        }
        s.swap(temp);
    }

    if (s.size() == k) {
        cout << 0 << endl;
    }
    else {
        for (int i = 1; i <= k; i++) {
            if (binary_search(in.begin(), in.end(), i)) continue;

            set<int> temp;
            temp.insert(i);
            for (int x : s) {
                temp.insert(x);
                if (x + i <= k) temp.insert(x+i);
            }

            if (temp.size() == k) {
                cout << i << endl;
                return;
            }
        }

        cout << -1 << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--) { input(); solve(); }
    return 0;
}
