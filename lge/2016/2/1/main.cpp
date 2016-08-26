//
#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    int x, y, n; cin >> x >> y >> n;
    double theta = M_PI*2 - atan((double)x / y)*2 - atan((double)(n-x) / y)*2;
    cout << n + (int)(y*theta) + 1 << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
