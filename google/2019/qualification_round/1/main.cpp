#include <iostream>
#include <string>
#include <deque>

using namespace std;

string str;

void solve() {
    deque<char> a, b;
    auto rit = str.rbegin();
    for (; rit != str.rend(); rit++) {
        const char &c = *rit;
        if (c == '4') {
            a.push_front('2');
            b.push_front('2');
        } else {
            a.push_front(c);
            b.push_front('0');
        }
    }

    while (b.front() == '0') {
        b.pop_front();
    }

    for (auto x: a) cout << x; cout << " ";
    for (auto x: b) cout << x; cout << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> str;
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
