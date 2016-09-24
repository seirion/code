// https://www.hackerrank.com/contests/world-codesprint-7/challenges/sock-merchant
// Sock Merchant 
#include <iostream>
#include <map>

using namespace std;

int main() {
    map <int, int> m;

    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        m[x]++;
    }

    int r = 0;
    for (auto it : m) {
        r += it.second / 2;
    }
    cout << r << endl;
    return 0;
}
