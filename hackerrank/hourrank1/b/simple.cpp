// https://www.hackerrank.com/contests/hourrank-1/challenges/xor-groups
#include <iostream>

using namespace std;

int power(int n) {
    const int MOD = 1000000007;
    int r = 1;
    while (n--) r = (r << 1) % MOD;
    return r;
}

int main() {
    int n; cin >> n;
    int one = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        one ^= x;
    }

    if (one == 0) {
        cout << power(n-1)-1 << endl;
    }
    else cout << 0 << endl;
    return 0;
}
