// https://www.hackerrank.com/contests/code-cpp-september-2015/challenges/deque-stl
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int n, k, capacity;
int tree[32768+1]; // 2^15 == 32768

void update(int index, int v) {
    index += capacity;
    tree[index] = v;
    index >>= 1;
    while (1 <= index) {
        int maxi = max(tree[index<<1], tree[(index<<1)+1]);
        if (tree[index] == maxi) break;
        tree[index] = maxi;
        index >>= 1;
    }
}

void solve() {
    memset(tree, 0, sizeof(tree));
    int i;
    deque<int> Q;

    cin >> n >> k;
    capacity = 1 << (32 - __builtin_clz(n-1));

    k--;
    for (i = 0; i < k; i++) {
        int x; scanf("%d", &x);
        Q.push_back(x);
        update(i, x);
    }

    for (; i < n; i++) {
        int x; scanf("%d", &x);
        Q.push_back(x);
        update(i, x);

        cout << tree[1] << " ";
        Q.pop_front();
        update(i-k, 0);
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
