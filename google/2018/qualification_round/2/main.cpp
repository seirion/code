#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> a, b;

void solve() {
    a.clear(); b.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (i & 1) b.push_back(x);
        else a.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto aa = a.begin();
    auto bb = b.begin();

    while (bb != b.end()) {
        if (*bb < *aa) {
            cout << (aa - a.begin()) * 2 << endl;
            return;
        }
        aa++;
        if (aa == a.end()) break;
        if (*aa < *bb) {
            cout << (bb - b.begin()) * 2 + 1 << endl;
            return;
        }
        bb++;
    }
    cout << "OK" << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
