// http://algospot.com/judge/problem/read/MEASURETIME
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, max_value;
int in[50000];
int tree[1000002]; // binary indexed tree

void input() {
    max_value = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        max_value = max(max_value, in[i]);
    }
}

int count_less_than(int x) { // [1, x]
    int s(0);
    while (x) {
        s += tree[x];
        x &= x - 1;
    }
    return s;
}

void update(int x) {
    while (x <= max_value+1) {
        tree[x]++;
        x += -x&x;
    }
}

void solve() {
    memset(tree, 0, sizeof(tree));
    int sum(0);
    for (int i = 0; i < n; i++) {
        sum += count_less_than(max_value+1) - count_less_than(in[i]+1);
        update(in[i]+1);
    }
    printf("%d\n", sum);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {input(); solve();}
    return 0;
}
