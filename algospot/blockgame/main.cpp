// http://algospot.com/judge/problem/read/BLOCKGAME
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int n;
int in;
char m[1 << 25];
vector<int> pre;

inline int indexof(int r, int c) { return 1 << (r * 5 + c); }

void input() {
    in = 0;
    for (int i = 0; i < 5; i++) {
        string s; cin >> s;
        for (int j = 0; j < 5; j++) {
            in <<= 1;
            if (s[j] == '#') in |= 1; // occupied
        }
    }
}

void build() {
    for (int r = 0; r < 5; r++) for (int c = 0; c < 4; c++) 
        pre.push_back(indexof(r,c) | indexof(r, c+1)); // --

    for (int r = 0; r < 4; r++) for (int c = 0; c < 5; c++) 
        pre.push_back(indexof(r,c) | indexof(r+1, c)); // |

    for (int r = 0; r < 4; r++) for (int c = 0; c < 4; c++) {
        pre.push_back(indexof(r,c) | indexof(r, c+1) | indexof(r+1, c+1)); // ㄱ
        pre.push_back(indexof(r,c) | indexof(r+1, c) | indexof(r+1, c+1)); // ㄴ
        pre.push_back(indexof(r,c) | indexof(r+1, c) | indexof(r, c+1)); // |-
        pre.push_back(indexof(r,c+1) | indexof(r+1, c) | indexof(r+1, c+1)); // -|
    }

    memset(m, 0xFF, sizeof(m));
}

bool go(int x) {
    //cout << "    " << x << endl;
    if (m[x] != -1) return m[x];

    char &r = m[x] = 0;
    for (int i : pre) {
        if ((x & i) == 0) {
            if (!go(x | i)) {
                r = 1;
                return r;
            }
        }
    }

    return r;
}

void solve() {
    if (go(in)) cout << "WINNING\n";
    else cout << "LOSING\n";
}

int main() {
    build();
    int t; cin >> t;
    while (t--) {input(); solve();}
    return 0;
}
