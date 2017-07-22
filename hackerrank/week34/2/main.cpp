#include <iostream>
#include <set>
#include <functional>

using namespace std;

bool a[1000001] = {0, }, b[1000001] = {0, };

bool exist(int gcd) {
    int x(0), y(0);
    int cand = gcd;
    while (cand <= 1000000) {
        if (a[cand]) x = cand;
        cand += gcd;
    }
    if (x == 0) return false;

    cand = gcd;
    while (cand <= 1000000) {
        if (b[cand]) y = cand;
        cand += gcd;
    }
    if (y == 0) return false;

    cout << x + y << endl;
    return true;
}

int main() {
    int n; cin >> n;
    int maxi = 1;
    for (int i = 0; i < n; i++) { int x; cin >> x; a[x] = true; maxi = max(maxi, x); }
    for (int i = 0; i < n; i++) { int x; cin >> x; b[x] = true; maxi = max(maxi, x); }

    for (int i = maxi; 1 <= i; i--) {
        if (exist(i)) break;
    }
    return 0;
}
