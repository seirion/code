// http://codeforces.com/contest/552/problem/A
// A. Vanya and Table
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n, x1, y1, x2, y2;
    cin >> n;
    int sum = 0;
    while (n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        sum += (abs(x1-x2)+1) * (abs(y1-y2)+1);
    }
    cout << sum << endl;
    return 0;
}
