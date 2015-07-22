// codeforces round313
// http://codeforces.com/contest/560/problem/B
#include <iostream>

using namespace std;

int a[3], b[3];

bool p(int a0, int b0, int a1, int b1, int a2, int b2) {
    return (a0 >= a1 + a2) && b0 >= max(b1, b2);
}

int main() {
    cin >> a[0] >> b[0] >> a[1] >> b[1] >> a[2] >> b[2];

    if (
            p(a[0], b[0], a[1], b[1], a[2], b[2]) ||
            p(a[0], b[0], b[1], a[1], a[2], b[2]) ||
            p(a[0], b[0], a[1], b[1], b[2], a[2]) ||
            p(a[0], b[0], b[1], a[1], b[2], a[2]) ||

            p(b[0], a[0], a[1], b[1], a[2], b[2]) ||
            p(b[0], a[0], b[1], a[1], a[2], b[2]) ||
            p(b[0], a[0], a[1], b[1], b[2], a[2]) ||
            p(b[0], a[0], b[1], a[1], b[2], a[2]))
        cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
