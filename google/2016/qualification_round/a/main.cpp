// https://code.google.com/codejam/contest/6254486/dashboard#s=p0
// A. Counting Sheep
#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

bool put(set<char> &s, int num) {
    while (num) {
        s.insert(num % 10);
        num /= 10;
    } 
    return s.size() == 10;
}

void solve() {
    int in; cin >> in;
    if (in == 0) {
        cout << "INSOMNIA\n";
        return;
    }

    int now = in;
    set<char> s;
    while (true) {
        if (put(s, now)) break;
        now += in;
    }

    cout << now << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}

