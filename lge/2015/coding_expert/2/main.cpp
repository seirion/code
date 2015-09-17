// LGE codejam 2015
// 2. 전구
#include <iostream>
#include <cstring>

using namespace std;

int n, m;
bool in[200000][2];

void input() {
    memset(in, 0, sizeof(in));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> y >> x;
        in[x-1][y-1] = true;
    }
}

void solve() {
    if (m & 1) {
        cout << -1 << endl;
        return;
    }

    enum { EVEN, ODD, };
    int total(0), state(EVEN);
    int y;
    for (int i = 0; i < n; i++) {
        switch(state) {
            case EVEN:
                if (!in[i][0] && !in[i][1]) {// both are off
                } else if (in[i][0] && in[i][1]) { // both are on
                    total++;
                }
                else {
                    y = in[i][0] ? 0 : 1;
                    state = ODD;
                }
                break;
            default: // case ODD
                if (!in[i][0] && !in[i][1]) {// both are off
                    total++;
                }
                else if (in[i][0] && in[i][1]) {// both are on
                    total++;
                    y ^= 1; // switch
                }
                else {
                    total += 1 + (in[i][y] ? 0 : 1);
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
