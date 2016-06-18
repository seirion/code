//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n = 10;
    vector<string> v;
    while (n--) {
        string s; cin >> s;
        v.push_back(s);
    }

    for (string &s : v) {
        cout << s;
    }
    cout << "XX\n";
}

int main() {
    int t; cin >> t;
    while (t--) { solve(); }
    return 0;
}
