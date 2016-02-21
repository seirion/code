// https://www.hackerrank.com/contests/w19/challenges/coolguy-and-two-subsequences
// Coolguy and Two Subsequences
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
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

    set<int> s; s.insert(-1); s.insert(n); // keep the index

    for (int i = 0; i < n-1; i++) {
        int &value = v[i].first;
        int &index = v[i].second;

        auto it = s.insert(index).first;
        auto prev = it; prev--;
        auto next = it; next++;

        long long left_c = *it - *prev;
        long long right_c = *next - *it;

        // left side
        long long vv = value * left_c % MOD * numofnum[right_c-1] % MOD;
        res = (res + vv) % MOD;

        while (true) { // -> right
            int begin = *next; next++;
            if (next == s.end()) break;

            int end = *next;

            int size = end - begin - 1;
            if (0 < size) {
                vv = value * left_c % MOD * right_c % MOD * numof(size) % MOD;
                res = (res + vv) % MOD;
            }
        }


        //right side
        vv = value * right_c % MOD * numofnum[left_c-1] % MOD;
        res = (res + vv) % MOD;

        while (prev != s.begin()) { // <-
            int begin = *prev; prev--;
            int end = *prev;

            int size = begin - end - 1;
            if (0 < size) {
                vv = value * left_c % MOD * right_c % MOD * numof(size) % MOD;
                res = (res + vv) % MOD;
            }
        }
    }

    cout << res << endl;
}

int main() {
    input();
    solve();
    return 0;
}
