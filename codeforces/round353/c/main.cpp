// http://codeforces.com/contest/675/problem/C
// C. Money Transfers
#include <iostream>
#include <map>

using namespace std;

int n;

int main() {
    map<long long, int> m;

    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sum += x;
        m[sum]++;
    }

    int r = 0;
    for (auto it : m) r = max(r, it.second);
    cout << n - r << endl;
    return 0;
}
