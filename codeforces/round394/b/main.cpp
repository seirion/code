// http://codeforces.com/contest/707/problem/B
#include <iostream>
#include <queue>

using namespace std;

int n, len;
int a[50], b[50];
deque<int> aa, bb;

bool ok() {
    while (len--) {
        if (aa == bb) return true;
        bb.push_back(bb.front());
        bb.pop_front();
    }

    return false;
}

int main() {
    cin >> n >> len;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 1; i < n; i++) {
        aa.push_back(a[i] - a[i-1]);
        bb.push_back(b[i] - b[i-1]);
    }

    aa.push_back(len - a[n-1] + a[0]);
    bb.push_back(len - b[n-1] + b[0]);

    if (ok()) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
