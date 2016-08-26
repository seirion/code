//
#include <iostream>
#include <cmath>

using namespace std;

int x, y, n;

double get_theta(int x1, int y1, int x2, int y2) {
    double len = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    return acos(y / len);
}

void solve() {
    cin >> x >> y >> n;
    double theta = M_PI*2 - get_theta(0, 0, x, y)*2 - get_theta(n, 0, x, y)*2;
    cout << n + (int)(y*theta) + 1 << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
