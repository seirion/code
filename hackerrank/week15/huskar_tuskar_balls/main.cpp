// https://www.hackerrank.com/contests/w15/challenges/huskar-tuskar-and-balls
// Weekly Challenges - Week 15 Huskar, Tuskar, and Balls
#include <cstdio>
#include <iostream>

using namespace std;

int tree[2 * 100000 + 1];
int dt[2 * 100000 + 1] = {0, }; // depth table
int child[2 * 100000 + 1] = {0, }; // # child
int gr[2 * 100000 + 1] = {0, }; // group

int depth(int a) {
    if (a == 1) return 0;
    int &d = dt[a];
    if (d == 0) d = depth(tree[a]) + 1;
    return d;
}

void build_depth(int size) {
    for (int i = 2; i <= size; i++) {
        dt[i] = depth(i);
    }
}

int group(int a) {
    int &g = gr[a];
    if (g == 0) {
        g = a;
        if (child[tree[a]] == 1) g = group(tree[a]);
    }
    return g;
}

void build_group(int size) {
    gr[1] = 1;
    for (int i = 2; i <= size; i++) {
        gr[i] = group(i);
    }
}

int depth(int a, int to) {
    return dt[a] - dt[to];
}

int common_parent(int a, int b) {
    if (gr[a] == gr[b]) return (dt[a] > dt[b] ? b : a);

    if (dt[a] > dt[b]) return common_parent(tree[gr[a]], b);
    if (dt[a] < dt[b]) return common_parent(a, tree[gr[b]]);
    return common_parent(tree[gr[a]], tree[gr[b]]);
}

void find_one(int a, int b) {
    int common = common_parent(a, b);
    if (common == b) {
        printf("%d %d\n", depth(a, common), dt[b]+1);
    }
    else {
        printf("%d %d\n", dt[a]+1, depth(b, common));
    }
}

int main() {
    int n, q, t, a, b;

    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &tree[i]);
        child[tree[i]]++;
    }

    build_depth(n);
    build_group(n);

    for (int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        find_one(a, b);
    }

    return 0;
}
