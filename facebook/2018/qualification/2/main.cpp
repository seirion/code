// https://www.facebook.com/hackercup/problem/175329729852444/
// Facebook Hacker Cup 2018 Qualification Round
// Interception
#include <iostream>

using namespace std;

int n;
int in[52];

void input() {
    cin >> n;
    for (int i = 0; i <= n; i++) cin >> in[i];
}

void solve(int no) {
    cout << "Case #" << no << ": ";
    if (n % 2 == 1) cout << 1 << endl << 0.0 << endl;
    else cout << 0 << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        input();
        solve(i);
    }
    return 0;
}
