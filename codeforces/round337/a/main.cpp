// http://codeforces.com/contest/610/problem/A
#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    if (n & 1 || n <= 4) {
        cout << 0 << endl;
        return 0;
    }
    n = n/2;

    int r = (n-1)/2;
    cout << r << endl;
    return 0;
}
