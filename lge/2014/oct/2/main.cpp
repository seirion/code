// hyungyu.jang@lge.com
// problem 2
// solution using Fenwick tree
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int in[2000 + 1];
int tree[2000 + 1]; // binary indexed tree

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> in[i]; // 1-based indexing
}

void reverse(int from, int to) { // 1-based indexing, [from, to]
    reverse(in + from, in + to + 1); // [from, to+1)
}

int count_less_than(int x) {
    int s(0);
    while (x) {
        s += tree[x];
        x &= x - 1;
    }
    return s;
}

void update(int x) {
    while (x <= n) {
        tree[x]++;
        x += -x&x;
    }
}

void count_rank() {
    memset(tree, 0, sizeof(tree));
    int sum(0);
    for (int i = 1; i <= n; i++) { // 1-based indexing
        sum += (count_less_than(in[i])+1) * in[i];
        update(in[i]);
    }
    cout << sum << endl;
}

void solve() {
    int k; cin >> k;
    count_rank();
    while (k--) {
        int from, to; cin >> from >> to;
        reverse(from, to);
        //for (int i = 1; i <= n; i++) cout << in[i] << " "; cout << endl;
        count_rank();
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) { input(); solve(); }
    return 0;
}

