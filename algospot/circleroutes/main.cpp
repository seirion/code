// https://algospot.com/judge/problem/read/CIRCLEROUTES
#include <iostream>
#include <string>

using namespace std;

int s, e, d, c;
string v;

int in() {
    int x = (v[0] - '0') * 10 + (v[1] - '0');
    int y = (v[3] - '0') * 10 + (v[4] - '0');
    return x * 60 + y;
}

void input() {
    s = e = d = c = 0;
    cin >> v; s = in();
    cin >> v; e = in();
    cin >> v; d = in();
    cin >> v; c = in();
}

void solve() {
    if (c <= e - s) {
        cout << (c + d - 1) / d << endl;
    }
    else {
        cout << (e - s) / d + 1 << endl;
    }
}

int main() {
    int t; cin >> t;
    while (t--) { input(); solve(); }
    return 0;
}
