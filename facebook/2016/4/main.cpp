// https://www.facebook.com/hackercup/problem/1525154397757404/
// Facebook Hacker Cup 2016 Qualification Round
// Text Editor
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<string> in;
int memo[301][301]; // [i-th_word][k]
int prefix[301][301];

void input() {
    in.clear();
    memset(memo, 0xFF, sizeof(memo));

    cin >> n >> k;
    in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    sort(in.begin(), in.end());
}

int common(const string &s1, const string &s2) {
    int i;
    for (i = 0; i < s1.size() && s2.size(); i++) {
        if (s1[i] != s2[i]) break;
    }
    return i;
}

void cal_prefix() {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            prefix[i][j] = prefix[j][i] = common(in[i], in[j]);
        }
    }
}

void solve(int num) {
    cal_prefix();

    memset(memo, 0x0F, sizeof(memo));

    for (int i = 0; i < n; i++) {
        memo[i][1] = in[i].size();
    }

    for (int j = 2; j <= k; j++) {
        for (int i = 0; i < n; i++) { // for each word
            int &mini = memo[i][j];
            mini = 123456789;
            for (int x = 0; x < i; x++) {
                mini = min(mini, memo[x][j-1] + (int)in[i].size() - prefix[x][i]);
            }
        }
    }

    int best = memo[0][k];
    for (int i = 1; i < n; i++) {
        best = min(best, memo[i][k]);
    }
    printf("Case #%d: %d\n", num, best*2 + k);
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        input();
        solve(i);
    }

    return 0;
}

