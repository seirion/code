#include <iostream>
#include <string>

using namespace std;

int n;
string str;

void solve() {
    string out;
    for (const auto c: str) {
        if (c == 'S') out.push_back('E');
        else out.push_back('S');
    }
    cout << out << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> str;
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
