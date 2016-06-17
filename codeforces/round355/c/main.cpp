// http://codeforces.com/contest/677/problem/C
// C. Vanya and Label
#include <iostream>
#include <map>

using namespace std;

const int MOD = 1e9 + 7;

map<char, int> m;

void pre() {
    int v = 0;
    for (char x = '0'; x <= '9'; x++) m[x] = v++;
    for (char x = 'A'; x <= 'Z'; x++) m[x] = v++;
    for (char x = 'a'; x <= 'z'; x++) m[x] = v++;
    m['-'] = v++;
    m['_'] = v++;
}

int power_of_3(int k) {
    long long r = 1;
    while (k--) {
        r = (r * 3) % MOD;
    }
    return (int)r;
}

int main() {
    pre();
    string s; cin >> s;

    long long r = 1;
    int k = 0;
    for (char c : s) {
        int i = m[c];
        k += 6 - __builtin_popcount(i); // the number of bits applicable
    }
    cout << power_of_3(k) << endl;
    return 0;
}
