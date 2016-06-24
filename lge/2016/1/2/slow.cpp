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

int find(const vector<int> &text, const vector<int> &pattern) {
    int limit = text.size() - pattern.size();
    for (int i = 0; i < limit; i++) {
        bool ok = true;
        for (int j = 0; j < pattern.size(); j++) {
            if (text[i+j] != pattern[j]) {
                ok = false;
                break;
            }
        }

        if (ok) return 1;
    }
    return 0;
}

void solve() {
    vector<int> text, pattern;
    for (int i = 0; i < n; i++) text.push_back(a[i]);
    for (int i = 0; i < n; i++) text.push_back(a[i]);
    for (int i = 0; i < n; i++) pattern.push_back(b[i]);

    if (0 < find(text, pattern)) {
        cout << 1 << endl;
        return;
    }
    
    reverse(pattern);
    cout << (0 < find(text, pattern) ? 1 : 0) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) { input(); solve(); }
    return 0;
}
