#include <iostream>

using namespace std;

int main() {
    int k; cin >> k;
    while (k--) {
        int x; cin >> x;
        cout << (__builtin_popcount(x) & 1) << endl;
    }
    return 0;
}
