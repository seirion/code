// https://www.hackerrank.com/contests/w23/challenges/commuting-strings
// Unexpected Problem
#include <iostream>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string s; int m;
    cin >> s >> m;

    string now;
    now.push_back(s[0]);
    int i, j(0), size(1), limit(s.size());
    for (i = 1; i < limit; i++) {
        if (s[j%size] == s[i]) j++;
        else {
            size = i + 1;
            j = 0;
        }
    }

    cout << (m / size) % MOD << endl;
    return 0;
}
