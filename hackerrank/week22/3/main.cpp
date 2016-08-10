// https://www.hackerrank.com/contests/w22/challenges/box-moving 
// Matching Sets
#include <iostream>
#include <algorithm>
#include <numeric>

int n;
long long a[100000], b[100000];
using namespace std;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    long long aa = accumulate(a, a+n, 0);
    long long bb = accumulate(b, b+n, 0);
    if (aa != bb) {
        cout << "-1\n";
    }
    else {
        sort(a, a+n);
        sort(b, b+n);
        long long sum(0);
        for (int i = 0; i < n; i++) {
            sum += abs(a[i] - b[i]);
        }
        cout << sum / 2 << endl;
    }
    return 0;
}
