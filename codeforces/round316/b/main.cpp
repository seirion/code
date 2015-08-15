// codeforces round316
// http://codeforces.com/contest/570/problem/B
#include <iostream>

int n, m;
using namespace std;

int main() {
    cin >> n >> m;

    if (n == 1) {
        cout << 1 << endl;
    }
    else if ((n+2) / 2 <= m) {
        cout << m-1 << endl;
    }
    else {
        cout << m+1 << endl;
    }
    return 0;
}
