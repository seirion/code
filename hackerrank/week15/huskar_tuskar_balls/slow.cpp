// https://www.hackerrank.com/contests/w15/challenges/huskar-tuskar-and-balls
// Weekly Challenges - Week 15 Huskar, Tuskar, and Balls
#include <cstdio>

using namespace std;

int tree[2 * 100000 + 1];
int dt[2 * 100000 + 1] = {0, }; // depth table

int depth(int a) {
    if (a == 1) return 0;
    int &d = dt[a];
    if (d == 0) d = depth(tree[a]) + 1;
    return d;
}

void build(int size) {
    for (int i = 2; i <= size; i++) {
        dt[i] = depth(i);
    }
}

int depth(int a, int to) {
    return dt[a] - dt[to];
}

int common_parent(int a, int b, int d1, int d2) {
    if (d1 > d2) {
        for (int i = d1; i > d2; i--) { a = tree[a]; }
    }
    else if (d2 > d1) {
        for (int i = d2; i > d1; i--) { b = tree[b]; }
    }
    while (a != b) {
        a = tree[a];
        b = tree[b];
    }
    return a;
}

void find_one(int a, int b) {
    int depth1 = depth(a, 1);
    int depth2 = depth(b, 1);
    int common = common_parent(a, b, depth1, depth2);
    if (common == a) {
        printf("%d %d\n", depth1+1, depth(b, common));
    }
    else if (common == b) {
        printf("%d %d\n", depth(a, common), depth2+1);
    }
    else {
        printf("%d %d\n", depth1+1, depth(b, common));
    }
}

int main() {
    int n, q, t, a, b;

    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &tree[i]);
    }

    build(n);

    for (int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        find_one(a, b);
    }

    return 0;
}

