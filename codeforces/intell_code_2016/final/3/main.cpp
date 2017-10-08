#include <iostream>

using namespace std;

long long x, y, n;

long long gcd(long long a, long long b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

long long aaa(long long a, long long b, long long limit) {
    while (a <= limit && b <= limit) {
        if (a == b) return a;
        if (a < b) a += x*2;
        else b += y*2;
    }

    return limit + 1;
}

int main() {
    cin >> x >> y >> n;
    long long limit = lcm(x, y);

    for (int i = 0; i < n; i++) {
        long long a, b; cin >> a >> b;

        long long diff = a - b;
        if (diff < 0) diff = -diff;

        if (a == b) {
            cout << a << endl;
            continue;
        }
        else if (diff % 2 == 1LL) {
            cout << -1 << endl;
            continue;
        }

        long long a1 = a;
        long long a2 = a + (x-a)*2;
        long long b1 = b;
        long long b2 = b + (y-b)*2;

        long long r = aaa(a1, b1, limit);
        r = min(r, aaa(a1, b2, r));
        r = min(r, aaa(a2, b1, r));
        r = min(r, aaa(a2, b2, r));

        if (r <= limit) cout << r << endl;
        else cout << -1 << endl;
    }

    return 0;
}
