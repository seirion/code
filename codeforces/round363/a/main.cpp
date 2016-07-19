// http://codeforces.com/contest/699/problem/A
#include <iostream>
#include <string>

using namespace std;

int n;
int in[200000];
string str;

void input() {
    cin >> n >> str;
    for (int i = 0; i < n; i++) cin >> in[i];
}

void solve() {
    int i, R(-1), r(0x7FFFFFFF);
    for (int i = 0; i < n; i++) {
        if (str[i] == 'R') {
            R = i;
        }
        else if (str[i] == 'L') {
            if (R != -1) {
                r = min(r, (in[i] - in[R]) / 2LL);
                R = -1;
            }
        }
    }

    if (r == 0x7FFFFFFF) r = -1;
    cout << r << endl;
}

int main() {
    input();
    solve();
    return 0;
}
