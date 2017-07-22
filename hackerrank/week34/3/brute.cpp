#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n, q;
int in[8001];

inline int num(int x) {
    return (x * (x + 1)) >> 1;
}

void query(int x, int y) {
    int r(0);
    for (int a = 1; a <= n; a++) {
        for (int b = a; b <= n; b++) {
            // count
            int xx(0), yy(0);
            for (int k = a; k <= b; k++) {
                if (in[k] == x) xx++;
                else if (in[k] == y) yy++;
            }
            if (xx == yy) r++;
        }
    }
    cout << r << endl;
}

int main() {
    in[0] = -1;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> in[i];

    while (q--) {
        int x, y; cin >> x >> y;
        query(x, y);
    }

    return 0;
}
