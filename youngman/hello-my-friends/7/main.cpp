#include <iostream>

using namespace std;

long long width, height, bx, by;

void input() {
}

long long gcd(long long a, long long b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

// brute-force
long long black_hole() {
    const long long period1 = (width-1) * 2;
    const long long period2 = (height-1) * 2;

    long long k1 = bx;
    long long k2 = width - 1 + (width - bx - 1);

    long long t1 = by;
    long long t2 = height - 1 + (height - by - 1);

    while (true) {
        if (k1 % period2 == t1) return k1;
        if (k1 % period2 == t2) return k1;
        if (k2 % period2 == t1) return k2;
        if (k2 % period2 == t2) return k2;

        k1 += period1;
        k2 += period1;
    }
}

void solve() {
    int n; cin >> n;
    while (n--) {
        cin >> width >> height >> bx >> by;
        cout << min(lcm((width-1)*2, (height-1)*2), black_hole()*2LL) << endl;
    }
}

int main() {
    input();
    solve();
    return 0;
}
