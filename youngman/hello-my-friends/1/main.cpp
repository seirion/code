#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <queue>
#include <map>
#include <set>

using namespace std;

const long long MAX = 9876543210LL;
int row, col, k;
int in[2002][2002];
long long best = MAX;
long long org[2002][2002]; // org
long long v[2002][2002]; // contains a broken cell
bool broken[2002][2002] = {false, };

void input() {
    cin >> row >> col >> k;
    //for (int r = 1; r <= row; r++) for (int c = 1; c <= col; c++) scanf("%d", &in[r][c]);
    for (int r = 1; r <= row; r++) for (int c = 1; c <= col; c++) cin >> in[r][c];
    while (k--) {
        int x, y;
        //scanf("%d %d", &x, &y);
        cin >> x >> y;
        broken[x+1][y+1] = true;
    }
    for (int r = 1; r <= row; r++) { in[r][0] = MAX; broken[r][0] = true; }
    for (int c = 1; c <= col; c++) { in[0][c] = MAX; broken[0][c] = true; }
    memset(v, 0x0f, sizeof(v));
    memset(org, 0x0f, sizeof(org));
    org[1][1] = v[1][1] = 0;
}

void solve() {
    for (int r = 1; r <= row; r++) for (int c = 1; c <= col; c++) {
        if (r == 1 && c == 1) continue; // skip the first

        if (broken[r][c]) {
            v[r][c] = min(org[r-1][c], org[r][c-1]) + in[r][c];
        } else {
            if (!broken[r-1][c] && !broken[r][c-1]) {
                org[r][c] = min(org[r-1][c], org[r][c-1]) + in[r][c];
                v[r][c] = min(v[r-1][c], v[r][c-1]) + in[r][c];
            } else {
                if (broken[r-1][c] && broken[r][c-1]) {
                    v[r][c] = min(v[r-1][c], v[r][c-1]) + in[r][c];
                    broken[r][c] = true;
                } else {
                    // org
                    if (broken[r-1][c]) org[r][c] = org[r][c-1] + in[r][c];
                    else org[r][c] = org[r-1][c] + in[r][c];
                    v[r][c] = min(v[r-1][c], v[r][c-1]) + in[r][c];
                }
            }
        }
    }
    cout << v[row][col] << endl;
}

int main() {
    std::ifstream in("/Users/babo/build/cpp/easy/input.txt");
    std::cin.rdbuf(in.rdbuf());
    input();
    solve();
    return 0;
}
