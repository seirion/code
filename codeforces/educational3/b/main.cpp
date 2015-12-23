// http://codeforces.com/contest/609/problem/B
#include <iostream>

using namespace std;

int main() {
    int n, m, x;
    int genres[11] = {0, };

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        genres[x]++;
    }

    unsigned int total = 0;
    for (int i = 1; i <= m; i++) {
        total += genres[i] * (n - genres[i]);
    }

    cout << total / 2 << endl;
    return 0;
}
