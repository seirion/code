// codeforces round318
// http://codeforces.com/contest/574/problem/C
#include <iostream>

using namespace std;

int n;
int in[100001];

int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

bool ok(int a, int b) { // a >= b
    while (a > b) {
        if (a % 2 == 0) {
            a /= 2;
        }
        else if (a % 3 == 0) {
            a /= 3;
        }
        else return false;
    }
    return true;
}

bool possible() {
    int now = in[0];
    for (int i = 1; i < n; i++) {
        now = gcd(now, in[i]);
    }

    for (int i = 0; i < n; i++) {
        if (!ok(in[i], now)) return false;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];

    if (possible()) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
