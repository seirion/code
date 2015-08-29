// codeforces round318
// http://codeforces.com/contest/574/problem/D
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int n;
deque<int> in;

void solve() {
    int c(0), even(0);
    in[0] = 1;

    for (int i = 1; i < n; i++) {
        if (in[i-1] < in[i]) {
            in[i] = in[i-1] + 1;
        }
        else {
            int x = i;
            while (0 < x) {
                if (in[x-1] <= in[x]) break;
                in[x-1] = in[x] + 1;
                x--;
            }
        }
    }

    cout << *max_element(in.begin(), in.end()) << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        in.push_back(x);
    }
    in.push_back(0);
    n++;
    solve();

    return 0;
}
