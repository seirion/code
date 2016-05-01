// https://code.google.com/codejam/contest/11254486/dashboard#s=p0
// Problem A. Getting the Digits
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const string STR [] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

vector<int> out;

char cc [] = { 'Z', 'X', 'U', 'W', 'G', 'F', 'H', 'O', 'S', 'N' };
char ii [] = { 0, 6, 4, 2, 8, 5, 3, 1, 7, 9 };

void solve() {
    multiset<char> s;
    vector<int> out;

    string in; cin >> in;
    for (char c : in) {
        s.insert(c);
    }

    for (int i = 0; i < 10; i++) {
        while (s.find(cc[i]) != s.end()) {
            out.push_back(ii[i]);
            for (char c : STR[ii[i]]) {
                s.erase(s.find(c));
            }
        }
    }

    sort(out.begin(), out.end());
    for (int i : out) cout << i;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}

