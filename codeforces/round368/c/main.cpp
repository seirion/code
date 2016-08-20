// http://codeforces.com/contest/707/problem/C
#include <iostream>
#include <cmath>

using namespace std;

bool ok2(long long x, long long c) {
    if (x & 1) return false;

    long long m = sqrt((double)x);
    long long n = m - 1;

    if (2 * m * n  == x) {
        cout << (m+n) * c << " " << (m*m + n*n) * c << endl;
        return true;
    }

    return false;
}

bool take2(long long x) {
    long long c = 1;
    while (x && !(x&1)) {
        if (ok2(x, c)) {
            return true;
        }

        x = x >> 1;
        c = c << 1;
    }
    return false;
}

int main() {
    long long xx, x, c(1);
    cin >> xx;

    x = xx;
    while (x && !(x & 1)) {
        x = x >> 1;
        c = c << 1;
    }

    if (x == 1 || x == 0) {
        if (!take2(xx)) {
            cout << -1 << endl;
        }
        return 0;
    }

    long long m = x / 2;
    long long n = m + 1;

    cout << 2 * m * n * c << " " << (m*m + n*n) * c << endl;
    return 0;
}
