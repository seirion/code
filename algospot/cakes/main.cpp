// http://algospot.com/judge/problem/read/CAKES
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int in[40];
int used[1201][1201] = {false, };

void input() {
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
}

void solve() {
    int sum = accumulate(in, in+n, 0);
    used[0][0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= 0; j--) {
            for (int k = sum; k >= 0; k--) {
                if (used[j][k]) {
                    used[j+in[i]][k] = true;
                    used[j][k+in[i]] = true;
                }
            }
        }
    }

    int best = sum;
    for (int j = 0; j <= sum; j++) {
        for (int k = 0; k <= sum; k++) {
            if (used[j][k]) {
                int total = max(sum - j - k, max(j, k));
                if (total < best) best = total;
            }
        }
    }
    cout << best << endl;
}

int main() {
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        input();
        solve();
    }
    return 0;
}
