// https://www.hackerrank.com/contests/w23/challenges/gears-of-war 
// Gears of War
#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n & 1) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}
