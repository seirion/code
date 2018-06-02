#include <iostream>

using namespace std;

int n, k, m;
int in[100001];

void solve() {
    while (m--) {
        int x; scanf("%d", &x);
        if (0 < x && k <= (--x)) {
            k = x - k;
        } else {
            x = -x;
            if ((n - x) <= k) {
                k = (n - x) + n - k - 1;
            }
        }
    }
    cout << k+1 << endl;
}

int main() {
    cin >> n >> k >> m;
    k--; // 0-based index
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    solve();
    return 0;
}
