// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-5-loops
// Day 5: Loops!

#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b, n, p(1);
        cin >> a >> b >> n;

        for (int i = 0; i < n; i++, p <<= 1) {
            a += p * b;
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}
