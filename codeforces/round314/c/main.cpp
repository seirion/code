// codeforces round314
// http://codeforces.com/contest/567/problem/C
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int64;

int n, k;
map<int64, vector<int> > tree;

int left(int64 v, int index) {
    auto it = lower_bound(tree[v].begin(), tree[v].end(), index);
    return it - tree[v].begin();
}

int right(int64 v, int index) {
    auto it = upper_bound(tree[v].begin(), tree[v].end(), index);
    return tree[v].end() - it;
}

int main() {
    cin >> n >> k;
    int64 x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        tree[x].push_back(i);
    }

    int64 c = 0;
    for (auto &i : tree) {
        int64 v = i.first;
        if (v % k) continue; // not divisible by k
        for (auto x : i.second) {
            c += (int64)left(v / k, x) * right(v * k, x);
        }
    }
    cout << c << endl;
    return 0;
}
