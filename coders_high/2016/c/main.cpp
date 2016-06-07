// https://www.acmicpc.net/problem/12792
// 주작 주 주작
#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (i == x) ok = false;
    }

    if (!ok) {
        cout << -1 << endl;
        return 0;
    }

    cout << 1000003 << endl;
    return 0;
}
