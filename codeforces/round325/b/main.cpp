// codeforces round325
// http://codeforces.com/contest/586/problem/A
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int in0[50] = {0, };
int in1[50] = {0, };
int col[50];
int n;

void input() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> in0[i];
    }

    for (int i = 0; i < n-1; i++) {
        cin >> in1[i];
    }
    
    for (int i = 0; i < n; i++) cin >> col[i];

    reverse(in1, in1+n);
    for (int i = 1; i < n; i++) {
        in0[i] += in0[i-1];
        in1[i] += in1[i-1];
    }
    reverse(in1, in1+n);
}

void solve() {
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x = in0[i] + in1[i] + col[i];
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    cout << v[0] + v[1] << endl;
}

int main() {
    input();
    solve();
    return 0;
}
