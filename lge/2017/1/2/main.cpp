#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int in[100000];

int max_distance(vector<int> &v) {
    int r = 0;
    for (int i = 1; i < v.size(); i++) {
        r = max(r, v[i] - v[i-1]);
    }
    return (r + 1) / 2;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];
    sort(in, in+n);
    vector<int> a, b;

    a.push_back(in[0]);
    b.push_back(in[0]);
    for (int i = 1; i + 1 < n; i+=2) {
        a.push_back(in[i]);
        b.push_back(in[i+1]);
    }
    a.push_back(in[n-1]);
    if (n % 2 == 0) b.push_back(in[n-1]);
    
    int m = max(max_distance(a), max_distance(b));
    cout << m << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
