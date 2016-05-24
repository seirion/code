// https://www.hackerrank.com/contests/w20/challenges/non-divisible-subset
// Non-Divisible Subset
#include <iostream>

using namespace std;

int n, k;
int in[100] = {0, };

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        in[x % k]++;
    }

    if (n == 1) {
        if (in[0]) cout << 0 << endl;
        else cout << 1 << endl;
        return 0;
    }

    int size = (k+1) / 2;
    int r = 0;
    if (in[0]) r++;
    for (int i = 1; i < size; i++) {
        r += max(in[i], in[k-i]);
    }
    if (k % 2 == 0 && in[k/2]) r++;

    cout << r << endl;
    return 0;
}
