// http://codeforces.com/contest/675/problem/A
// A. Infinite Sequence
#include <iostream>

using namespace std;

int main() {
    int begin, jump, target;
    cin >> begin >> target >> jump;
    
    while (true) {
        if (begin == target) {
            cout << "YES\n";
            return 0;
        }
        begin += jump;

        if (0 < jump && target < begin) break;
        if (jump < 0 && begin < target) break;
        if (jump == 0) break;
    }
    cout << "NO\n";
    return 0;
}
