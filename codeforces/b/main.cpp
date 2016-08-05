// http://codeforces.com/contest/703/problem/B
#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int in[100001];
int kk[100001];
int sum[100001];

bool capital(int x) {
    auto it = lower_bound(kk+1, kk+k+1, x);
    return *it == x;
}

void input() {
    sum[0] = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) { cin >> in[i]; }
    in[0] = in[n];
    for (int i = 1; i <= k; i++) {
        cin >> kk[i];
        sum[i] = sum[i-1] + in[kk[i]];
    }
}

int indexof(int x) {
    auto it = lower_bound(kk+1, kk+k+1, x);
    return it - kk;
}

long long connection_capital(int x) {
    long long me = in[x];
    if (capital(x)) {
        long long all = (x == 1 && kk[k] == n ? sum[k-1] : sum[k]);
        int index = indexof(x);
        all -= (index != k && kk[index+1] == x+1 ? sum[index+1] : sum[index]);
        return me * all;
    }
    else {
        long long all = sum[k];
        if (capital(x-1)) all -= in[x-1];
        if (capital(x+1)) all -= in[x+1];
        if (x == 1 && capital(n)) all -= in[n];
        if (x == n && capital(1)) all -= in[1];
        return me * all;
    }
}

void solve() {
    long long r = 0;
    for (int i = 1; i <= n; i++) {
        r += in[i] * in[i-1]; // base connection
        r += connection_capital(i);
    }
    cout << r << endl;
}

int main() {
    input(); solve();
}
