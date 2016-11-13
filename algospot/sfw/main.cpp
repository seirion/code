// http://algospot.com/judge/problem/read/SFW
#include <iostream>
#include <cmath>

using namespace std;

long long row, col, r_from, c_from, r_end, c_end, rjump, cjump;

void solve() {
    cin >> row >> col >> r_from >> c_from >> r_end >> c_end >> rjump >> cjump;

    cout << ((long long) abs(r_from - r_end) + rjump - 1) / rjump +
        ((long long) abs(c_from - c_end) + cjump - 1) / cjump
        << endl;
}

int main() {
    int t; cin >> t;
    while (t--) { solve();}
    return 0;
}
