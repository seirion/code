//
#include <iostream>

using namespace std;

void solve() {
    string s; cin >> s;
    
    string out;
    bool leading_zero = true;
    for (char c : s) {
        if ('0' <= c && c <= '9') {
            if (c != '0' || !leading_zero) {
                out.push_back(c);
                leading_zero = 0;
            }
        }
    }
    if (out.empty()) out = "0";
    cout << out << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
