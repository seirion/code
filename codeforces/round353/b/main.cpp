// http://codeforces.com/contest/675/problem/B
// B. Restoring Painting
#include <iostream>

using namespace std;

int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    long long r = 0;
    for (int x = 1; x <= n; x++) {
        int y = x + b - c;
        int z = x + a - d;
        int w = a + y - d;
        if (1 <= y && y <= n && 1 <= z && z <= n && 1 <= w && w <= n) r++;
    }
    cout << r * n << endl;
    return 0;
}
