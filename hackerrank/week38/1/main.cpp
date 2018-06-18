#include <iostream>

using namespace std;

int n, k, m;
int in[1000];

void solve() {
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) {
        cin >> in[i];
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += in[i];
        if (k <= sum) {
            cout << i + 1 << endl;
            return;
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
