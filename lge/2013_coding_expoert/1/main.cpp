#include <iostream>
#include <climits>

using namespace std;

int n;
int in[10];
long long best;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];
}

void iterate(int remain/*bitset*/, long long current) {
    if (remain == 0) {
        best = min(best, current);
        return;
    }
    if (best <= current) return;

    int temp = remain;
    while (temp) {
        int index = __builtin_ctz(temp);
        iterate(remain & ~(1<<index), current * in[index]);
        temp &= temp - 1;
    }
}

void solve() {
    best = LLONG_MAX;
    iterate((1 << n) - 1, 1LL);
    cout << best << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        input(); solve();
    }
}
