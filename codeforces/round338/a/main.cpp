// http://codeforces.com/contest/615/problem/A
// A. Bulbs
#include <iostream>

using namespace std;

int n, m;
bool in[101] = {false};

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        for (int j = 0; j < num; j++) {
            int x; cin >> x;
            in[x] = true;
        }
    }

    bool yes = true;
    for (int i = 1; i <= m; i++) {
        if (!in[i]) {
            yes = false;
            break;
        }
    }

    cout << (yes ? "YES" : "NO") << "\n";
    return 0;
}
