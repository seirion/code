// http://codeforces.com/contest/699/problem/C
#include <iostream>
#include <cstring>

using namespace std;

int n;
int in[100];
int memo[100][100];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];
    memset(memo, 0xFF, sizeof(memo));
}

void solve() {
    int r = 0;
    int prev = 0;
    for (int begin = 0; begin < n; begin++) {
        if (in[begin] == 0) {
            r++;
            prev = 0;
        }
        else if (in[begin] < 3) {
            if (prev == in[begin]) {
                r++;
                prev = 0;
            } else {
                prev = in[begin];
            }
        } else {
            int end = begin + 1;
            for (; end < n; end++) if (in[end] != 3) break;

            if (end == n) break;
            else {
                if (prev == 0 || in[end] == 0) {
                    begin = end;
                    prev = in[end];
                    if (in[end] == 0) r++;
                }
                else {
                    if ((in[begin-1] == in[end] && (end - begin) % 2 == 0) ||
                            (in[begin-1] != in[end] && (end - begin) % 2 == 1)) {
                        r++;
                        begin = end;
                        prev = 0;
                    }
                    else {
                        begin = end;
                        prev = in[end];
                    }
                }
            }
        }
    }
    cout << r << endl;
}

int main() {
    input();
    solve();
    return 0;
}
