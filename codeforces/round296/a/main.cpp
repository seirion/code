// http://codeforces.com/contest/527/problem/A
// A. Playing with Paper
#include <iostream>

using namespace std;

typedef long long int64;

int64 count(int64 a, int64 b) {
    int64 c = a / b;
    a = a % b;
    if (a) c += count(b, a);
    return c;
}

int main() {
    int64 a, b;
    cin >> a >> b;
    cout << count(a, b);
    return 0;
}
