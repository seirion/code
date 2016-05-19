// http://codeforces.com/contest/675/problem/A
// A. Infinite Sequence
#include <iostream>

using namespace std;

int main() {
    int begin, jump, target;
    cin >> begin >> target >> jump;
    
    if (jump == 0) {
        if (begin == target) goto YES;
        else goto NO;
    }
    if (0 < jump && target < begin) goto NO;
    if (jump < 0 && begin < target) goto NO;

    target -= begin;
    if (target % jump == 0) goto YES;
    else goto NO;

YES:
    cout << "YES\n";
    return 0;
NO:
    cout << "NO\n";
    return 0;
}
