#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

long long n, k;
map<long long, long long> m;

int main() {
    cin >> n >> k;

    for (long long i = 0; i < n; i++) {
        long long x; cin >> x;
        m[x - i * k]++;
    }

    long long v = 0;
    for (auto x : m) {
        v = max(v, x.second); 
    }
    cout << n - v << endl;
    return 0;
}
