// https://www.hackerrank.com/contests/w19/challenges/coolguy-and-two-subsequences
// Coolguy and Two Subsequences
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int n;
int in[200000];
long long numofnum[200000]; // accumulation of numof

vector<pair<int, int>> v; // pair of : value - index

long long numof(long long x) {
    return x * (x+1) / 2;
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);

    for (int i = 0; i < n; i++) {
        v.push_back(make_pair(in[i], i));
    }
    sort(v.begin(), v.end());

    numofnum[0] = 0;
    for (int i = 1; i < n; i++) {
        numofnum[i] = (numofnum[i-1] + numof(i)) % MOD;
    }
}

int left_count(int start, int value) {
    int i = start - 1;
    while (0 <= i) {
        if (in[i] <= value) break;
        i--;
    }
    return start - i;
}

int right_count(int start, int value) {
    int i = start + 1;
    while (i < n) {
        if (in[i] < value) break;
        i++;
    }
    return i - start;
}

void solve() {
    long long res = 0;

    for (int i = 0; i < n-1; i++) {
        int &value = v[i].first;
        int &index = v[i].second;

        long long left_c = left_count(index, value);
        long long right_c = right_count(index, value);

        // left side
        if (1 < right_c) {
            long long v = value * left_c % MOD * numofnum[right_c-1] % MOD;
            res = (res + v) % MOD;
        }

        int begin = -1;
        for (int x = index+right_c; x < n; x++) { // -> right
            if (value <= in[x]) {
                if (begin == -1) begin = x;
            }
            else {
                if (begin != -1) {
                    int size = x - begin;
                    long long v = value * left_c % MOD * right_c % MOD * numof(size) % MOD;
                    res = (res + v) % MOD;
                    begin = -1;
                }
            }
        }
        if (begin != -1) {
            int size = n - begin;
            long long v = value * left_c % MOD * right_c % MOD * numof(size) % MOD;
            res = (res + v) % MOD;
            begin = -1;
        }


        // right side
        if (1 < left_c) {
            long long v = value * right_c % MOD * numofnum[left_c-1] % MOD;
            res = (res + v) % MOD;
        }
        for (int x = index-left_c; 0 <= x; x--) { // <- left
            if (value < in[x]) {
                if (begin == -1) begin = x;
            }
            else {
                if (begin != -1) {
                    int size = begin - x;
                    long long v = value * left_c % MOD * right_c % MOD * numof(size) % MOD;
                    res = (res + v) % MOD;
                    begin = -1;
                }
            }
        }
        if (begin != -1) {
            int size = begin+1;
            long long v = value * left_c % MOD * right_c % MOD * numof(size) % MOD;
            res = (res + v) % MOD;
        }
    }

    cout << res << endl;
}

int main() {
    input();
    solve();
    return 0;
}
