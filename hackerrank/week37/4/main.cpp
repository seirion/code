#include <iostream>

using namespace std;

const int SIZE = 400;
const int MAXS = 100001;

int large[MAXS] = {0, };
int small[SIZE][SIZE] = {0, };

void put(int m, int a, int b) { // m : +1 or -1
    if (SIZE <= a) { // large
        while (b < MAXS) {
            large[b] += m;
            b += a;
        }
    } else { // small
        small[a][b] += m;
    }
}

void query(int x) {
    int r = large[x];
    for (int i = 1; i < SIZE; i++) {
        r += small[i][x % i];
    }
    cout << r << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        char c; cin >> c;
        if (c == '?') {
            int a; cin >> a;
            query(a);
        } else {
            int a, b; cin >> a >> b;
            put(c == '+' ? 1 : -1, a, b % a);
        }
    }
    return 0;
}
