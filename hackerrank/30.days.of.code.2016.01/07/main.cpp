// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-7-arrays
// Day 7: Arrays!

#include <iostream>

using namespace std;

int n;
int in[1001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];
    while (--n >= 0) {
        cout << in[n] << " ";
    }
    cout << endl;

    return 0;
}
