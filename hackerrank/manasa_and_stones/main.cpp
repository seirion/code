// https://www.hackerrank.com/challenges/manasa-and-stones
// Manasa and Stones
#include <iostream>
#include <queue>
#include <set>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    set<pair<int, int> > s; // num, count
    s.insert(make_pair(0, 1));
    set<int> out;

    while (!s.empty()) {
        set<pair<int, int> > temp;
        for (auto x : s) {
            if (x.second == n) {
                out.insert(x.first);
            }
            else {
                s.insert(make_pair(x.first + a, x.second+1));
                s.insert(make_pair(x.first + b, x.second+1));
            }
        }
        s.swap(temp);
    }

    for (int x : out) cout << x << " ";
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
