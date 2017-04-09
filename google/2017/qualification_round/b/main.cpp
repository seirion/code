// https://code.google.com/codejam/contest/3264486/dashboard#s=p1
// Problem B. Tidy Numbers
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string s; // input

string remove_leading_zero(string in) {
    int i = 0;
    for (; i < in.size(); i++) {
        if (in[i] != '0') break;
    }
    return in.substr(i, in.size() - i);
}

string real_max() {
    string out;
    out.push_back(s[0]);

    int i = 1;
    for (; i < s.size(); i++) {
        if (s[i-1] > s[i]) break;
        out.push_back(s[i]);
    }

    if (out.size() == s.size()) return out;

    char &back = out[out.size() - 1];
    back--; // back is not '0'

    while (1 < out.size()) {
        char &back = out[out.size() - 1];
        char &prev = out[out.size() - 2];

        if (back < prev) {
            prev--;
            out.pop_back();
        } else break;
    }

    while (out.size() < s.size()) out.push_back('9');
    return remove_leading_zero(out);
}

void solve() {
    cin >> s;
    cout << real_max() << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}

