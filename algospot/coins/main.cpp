#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int coin[100];
long long w[5000+1];
int m, n;
long long c;

void count(int index) {
    for (int i = coin[index]; i <= m; i++) {
        w[i] += w[i-coin[index]];
    }
}

void solve() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) cin >> coin[i];
    sort(coin, coin + n);
    memset(w, 0, sizeof(long long) * 5001);
    w[0] = 1;
    for (int i = 0; i < n; i++) count(i);

    cout << (w[m] % 1000000007LL) << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) solve();
    return 0;
}
