// http://codeforces.com/contest/703/problem/A
#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int x(0), y(0);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if (a < b) y++;
        else if (b < a) x++;
    }
    if (y < x) cout << "Mishka\n";
    else if (x < y) cout << "Chris\n";
    else cout << "Friendship is magic!^^";

    return 0;
}
