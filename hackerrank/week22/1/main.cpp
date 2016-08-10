// https://www.hackerrank.com/contests/w22/challenges/cookie-party
// Cookie Party
#include <iostream>

using namespace std;

int main() {
    int person, cookie; cin >> person >> cookie;
    if (cookie % person == 0) cout << 0 << endl;
    else cout << person - (cookie % person) << endl;
    return 0;
}
