// http://codeforces.com/contest/677/problem/A
// A. Vanya and Fence
#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int r = n;
    while (n--) {
        int x; cin >> x;
        if (k < x) r++;
    }
    cout << r << endl;

    return 0;
}
