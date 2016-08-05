// https://www.hackerrank.com/contests/world-codesprint-5/challenges/string-construction
#include <iostream>
#include <string>
#include <set>

using namespace std;

void solve() {
    string str; cin >> str;
    set<char> s;
    for (auto x : str) {
        s.insert(x);
    }
    cout << s.size() << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
