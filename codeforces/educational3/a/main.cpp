// http://codeforces.com/contest/609/problem/A
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int in[100001];

int main() {
    int n, m, i;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> in[i];
    }
    sort(in, in+n, greater<int>());

    i = 0;
    while (m > 0) {
        m -= in[i++];
    }
    cout << i << endl;
    return 0;
}
