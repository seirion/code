// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-10-binary-numbers
// Day 10: Binary Numbers!

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void print(int n) {
    string s;
    while (n != 0) {
        if (n & 1) s.push_back('1');
        else s.push_back('0');
        n >>= 1;
    }

    reverse(s.begin(), s.end());
    cout << (s.empty() ? "" : s) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        print(n);
    }
    return 0;
}
