// http://codeforces.com/contest/677/problem/B
// B. Vanya and Food Processor
#include <iostream>

using namespace std;

int n, h, k;
int in[100001];

int main() {
    cin >> n >> h >> k;
    for (int i = 0; i < n; i++) cin >> in[i];

    long long r(0), now(0);
    for (int i = 0; i < n; i++) {
        if (h < now + in[i]) {
            long long c = (now - (h - in[i]) + k - 1) / k;
            r += c;
            now -= min(now, (c * k));
        }
        now += in[i];
    }

    if (0 < now) r += (now + k - 1) / k;
    cout << r << endl;
    return 0;
}
