// http://algospot.com/judge/problem/read/PDNA
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string in[10];
string solution;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    sort(in, in + n);
    
}

void is_palindromic(const vector<int> &v) {
    string s;
    for (auto i : v) {
        s += in[i];
    }
    int low(0), high(s.size() - 1);
    while (low < high) {
        if (s[low] != s[high]) return;
        low++; high--;
    }

    if (solution.empty() || solution > s) {
        solution = s;
    }
}

void permutation_check(vector<int> &cur, int remain) {
    if (remain == 0) {
        is_palindromic(cur);
        return;
    }

    int all = remain;
    while (remain) {
        int t = __builtin_ctz(remain);
        cur.push_back(t);
        permutation_check(cur, all & ~(1<<t));
        cur.pop_back();
        remain &= remain - 1;
    }
}

void solve() {
    vector<int> vv;
    solution.clear();
    permutation_check(vv, (1 << n) - 1);
    cout << solution << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) { input(); solve(); }
    return 0;
}
