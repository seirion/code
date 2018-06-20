#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

int n, k;
map<int, int> m;

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        m[x - i * k]++;
    }

    int v = 0;
    for (auto x : m) {
        v = max(v, x.second); 
    }
    cout << n - v << endl;
    return 0;
}
