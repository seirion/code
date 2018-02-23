// https://www.hackerrank.com/challenges/between-two-sets/problem
#include <iostream>
#include <vector>

using namespace std;

vector<int> v1, v2;

int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int a, b;
    cin >> a >> b;
    v1.resize(a);
    v2.resize(b);
    while (a--) cin >> v1[a];
    while (b--) cin >> v2[b];

	int _lcm = v1[0];
    for (auto x: v1) _lcm = lcm(_lcm, x);

	int _gcd = v2[0];
    for (auto x: v2) _gcd = gcd(_gcd, x);

    int r = 0; int j = _lcm;
    while (_lcm <= _gcd) {
        if (_gcd % _lcm == 0) r++;
        _lcm += j;
    }
    cout << r << endl;
    return 0;
}
