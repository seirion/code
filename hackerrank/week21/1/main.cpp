// https://www.hackerrank.com/contests/w21/challenges/kangaroo
// Kangaroo
#include <iostream>

using namespace std;

int a1, r1, a2, r2;

bool ok() {
    if (a1 == a2) return true;

    if ((a1 - a2) % (r2 - r1) == 0) {
        return (0 < (a1 - a2) / (r2 - r1));
    }
    return false;
}

int main() {
    cin >> a1 >> r1 >> a2 >> r2;

    cout << (ok() ? "YES\n" : "NO\n");
    return 0;
}
