// http://algospot.com/judge/problem/read/BALLPAINTING
#include <iostream>

using namespace std;

const int MOD = 1000000007;
int n;
long long out[1001];

void build() {
    out[1] = 2L;
    for (int i = 2; i <= 1000; i++) {
        out[i] = (12 + 8 * (i-2)) * out[i-1];
        out[i] = out[i] % MOD;
    }
}

int main() {
    build();
    while (true) {
        cin >> n; if (n == 0) break;
        cout << out[n] << endl;
    }
    return 0;
}
