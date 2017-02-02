// http://codeforces.com/contest/761/problem/A
#include <iostream>

#ifndef abs
#define abs(a, b) ((a < b) ? (b - a) : (a - b))
#endif

using namespace std;

int main() {
    int a, b; cin >> a >> b;

    if (a == 0 && b == 0) goto NO;

    if (abs(a, b) == 1 || a == b) goto YES;
    else goto NO;

YES:
    cout << "YES" << endl;
    return 0;
NO:
    cout << "NO" << endl;
    return 0;
}

