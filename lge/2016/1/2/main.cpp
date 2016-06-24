// 직각다각형
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[100000], b[100000];

inline void set(vector<int> &x, int i, int plus) { x[i] = plus * abs(x[i]); }

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
}

void reverse(vector<int> &pattern) {
    bool temp = 0 < pattern[n-1];
    for (int i = n-1; 0 < i; i--) { set(pattern, i, 0 < pattern[i-1] ? 1 : -1); }
    set(pattern, 0, 0 < temp ? 1 : -1);
    reverse(pattern.begin(), pattern.end());
    for (int i = 0; i < n; i++) pattern[i] = -pattern[i];
}

int kmp(const vector<int> &text, const vector<int> &pattern) {
    // need to implements
}

void solve() {
    vector<int> text, pattern;
    for (int i = 0; i < n; i++) text.push_back(a[i]);
    for (int i = 0; i < n; i++) text.push_back(a[i]);
    for (int i = 0; i < n; i++) pattern.push_back(b[i]);

    if (0 < kmp(text, pattern)) {
        cout << 1 << endl;
        return;
    }
    
    reverse(pattern);
    cout << (0 < kmp(text, pattern) ? 1 : 0) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) { input(); solve(); }
    return 0;
}
