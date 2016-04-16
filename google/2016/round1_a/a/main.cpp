// https://code.google.com/codejam/contest/4304486/dashboard#s=p0&a=2
// Problem A. The Last Word
#include <cstdio>
#include <iostream>
#include <string>
#include <deque>

using namespace std;

string str;
void solve() {
    cin >> str;
    deque<char> out;
    int size = str.size();
    out.push_back(str[0]);
    for (int i = 1; i < size; i++) {
        if (out[0] <= str[i]) out.push_front(str[i]);
        else  out.push_back(str[i]);
    }

    for (char c : out) cout << c;
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

