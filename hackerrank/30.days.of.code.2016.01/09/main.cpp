// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-9-recursion
// Day 9: Recursion!

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

int main() {
    int a, b; cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}
