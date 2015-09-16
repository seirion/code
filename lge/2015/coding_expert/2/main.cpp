// LGE codejam 2015
// 2. ..
#include <iostream>
#include <cstring>

using namespace std;

int n, m;
bool in[200000][2];

void input() {
    memset(in, 0, sizeof(in));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int r, c; cin >> r >> c;
        in[c-1][r-1] = true;
    }
}

void solve() {
    if (m & 1) {
        cout << -1 << endl;
        return;
    }

    enum { EVEN, ODD, };
    int total(0), state(EVEN);
    int row;
    for (int i = 0; i < n; i++) {
        switch(state) {
            case EVEN:
                if (!in[i][0] && !in[i][1]) {// both are off
                } else if (in[i][0] && in[i][1]) { // both are on
                    total++;
                }
                else {
                    row = in[i][0] ? 0 : 1;
                    state = ODD;
                }
                break;
            default: // case ODD
                if (!in[i][0] && !in[i][1]) {// both are off
                    total++;
                }
                else if (in[i][0] && in[i][1]) {// both are on
                    total++;
                }
                else {
                    total += 1 + (in[i][row] ? 0 : 1);
                    state = EVEN;
                }
                break;
        }
    }
    cout << total << endl;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        input();
        solve();
    } 
    return 0;
}
