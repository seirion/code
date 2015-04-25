// http://codeforces.com/contest/535/problem/B
// B. Tavas and SaDDas
#include <iostream>

using namespace std;

typedef unsigned int uint32;

int main() {
    uint32 n;
    cin >> n;
    int k = 32 - __builtin_clz(++n) - 2;
    for (int i = k; i >= 0; i--) {
        cout << ((n & (1 << i)) ? "7" : "4");
    }
    cout << endl;
    return 0;
}
