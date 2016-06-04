// http://codeforces.com/contest/677/problem/C
// C. Vanya and Label
#include <iostream>
#include <map>

using namespace std;

const int MOD = 1e9 + 7;

map<char, int> m;
int comb[9][9] = {0, };

void pre() {
    int v = 0;
    for (char x = '0'; x <= '9'; x++) m[x] = v++;
    for (char x = 'A'; x <= 'Z'; x++) m[x] = v++;
    for (char x = 'a'; x <= 'z'; x++) m[x] = v++;
    m['-'] = v++;
    m['_'] = v++;

    for (int r = 0; r < 9; r++) {
        comb[r][0] = 1;
        for (int c = 1; c <= r; c++) {
            comb[r][c] = comb[r-1][c-1] + comb[r-1][c];
        }
    }
}

int aaa(int n) {
    long long r = 0;
    for (int i = 0; i <= n; i++) {
        r += comb[n][i] * (1 << (n-i));
    }
    return r;
}

int main() {
    pre();
    string s; cin >> s;

    long long r = 1;
    for (char c : s) {
        int i = m[c];
        int x = 6 - __builtin_popcount(i); // the number of characters which cover all bits
        r = r * aaa(x) % MOD;
    }
    cout << r << endl;
    return 0;
}
