// http://codeforces.com/contest/610/problem/C
#include <iostream>

using namespace std;
int n;

void print(int bit) {
    int limit = 1 << n;
    for (int i = 0; i < limit; i++) {
        cout << (bit&1?'+':'*');
        bit >>= 1;
    }
    cout << endl;
}

void rec(int bit, int x) {
    if (x == n) {
        print(bit);
        return;
    }

    int shift = 1 << x;
    int flag = (1 << shift)-1;
    rec((bit<<shift) | (bit&flag), x+1);
    rec((bit<<shift) | (~bit&flag), x+1);
}

int main() {
    n; cin >> n;

    rec(1, 0);
    return 0;
}
