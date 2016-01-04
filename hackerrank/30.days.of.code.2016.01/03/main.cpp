// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-3-if-statements
// Day 3: If-Else Statements!

#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    bool weird = true;
    if (n & 1) { // odd
        weird = true;
    }
    else {
        if (2 <= n && n <= 5) weird = false;
        else if (n <= 20) weird = true;
        else weird = false;
    }

    cout << (weird ? "" : "Not ") << "Weird\n";
    return 0;
}
