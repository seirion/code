// https://code.google.com/codejam/contest/6254486/dashboard#s=p0
// A. Counting Sheep
#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

string in("1");
string pluss("1");

bool put(set<char> &s, const string &str) {
    for (char c : str) { s.insert(c); }
    return s.size() == 10;
}

void add(string &now, string &in) {
    int size = in.size();
    int prev = 0;
    int i;
    for (i = 0; i < size; i++) {
        now[i] += in[i] + prev;
        prev = now[i] / 10;
        now[i] = now[i] % 10;
    }

    size = now.size();
    for (; i < size && 0 < prev; i++) {
        now[i] += prev;
        prev = now[i] / 10;
        now[i] = now[i] % 10;
    }

    if (0 < prev) now.push_back(prev);
}

void solve() {

    string now = in;
    set<char> s;
    int trying = 0;
    while (true) {
        if (put(s, now)) break;
        add(now, in);
    }

    for (auto it = now.rbegin(); it != now.rend(); it++) cout << (int)*it;
    cout << endl;
}

int main() {
    in[0] -= '0';
    pluss[0] -= '0';

    for (int i = 1; i <= 1000000; i++) {
        printf("Case #%d: ", i);
        solve();
        add(in, pluss);
    }
}

