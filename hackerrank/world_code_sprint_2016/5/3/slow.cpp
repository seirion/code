// https://www.hackerrank.com/contests/world-codesprint-5/challenges/short-palindrome
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int MOD = 1e9 + 7;

vector<int> v[26];
int m[26][1000001] = {0, };

long long comb2(int s) {
    return s * (s - 1) / 2 % MOD;
}

int main() {
    string str; cin >> str;
    long long r = 0;
    int size = str.size();

    for (int i = 0; i < size; i++) {
        int index = str[i]-'a';
        v[index].push_back(i);
        for (int j = 0; j < 26; j++) {
            if (index == j) m[j][i] = (i ? m[j][i-1] : 0) + 1;
            else m[j][i] = (i ? m[j][i-1] : 0);
        }
    }

    for (int i = 0; i < 26; i++) {
        int s = v[i].size();
        for (int j = 0; j < s; j++) {
            int begin = v[i][j];
            for (int k = j+1; k < s; k++) {
                int end = v[i][k];
                for (int p = 0; p < 26; p++) {
                    int cc = m[p][end-1] - m[p][begin];
                    r = (r + comb2(cc)) % MOD;
                }
            }
        }
    }

    cout << r << endl;
    return 0;
}

