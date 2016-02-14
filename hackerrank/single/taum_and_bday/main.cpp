// https://www.hackerrank.com/challenges/taum-and-bday
// Taum and B'day
#include <iostream>

using namespace std;

long long x, y, costx, costy, z;

long long all_x() {
    return (x+y) * costx + (y*z);
}

long long all_y() {
    return (x+y) * costy + (x*z);
}

long long x_y() {
    return x*costx + y*costy;
}

void solve() {
    cin >> x >> y >> costx >> costy >> z;

    long long best = x_y();
    best = min(best, all_x());
    best = min(best, all_y());
    cout << best << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
