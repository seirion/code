// LGE codejam 2015
// 4. 우주 구조대
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int n, k;
set<int> in[500001];
vector<int> tree[500001];
int depth[500001] = {0, };

void calc_ancestor_pointer(int child) {
    int jump(1);
    while (depth[child] > (1<<jump)) {
        tree[child].push_back( tree[tree[child].back()][jump-1] );
        jump++;
    }
}

void input() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        in[a].insert(b);
        in[b].insert(a);
    }
}

void refine(int parent) {
    depth[1] = 1;
    queue<int> Q;
    Q.push(parent);
    while (!Q.empty()) {
        int now = Q.front(); Q.pop();
        for (auto child : in[now]) {
            in[child].erase(now);
            tree[child].push_back(now);
            depth[child] = depth[now] + 1;
            calc_ancestor_pointer(child);
            Q.push(child);
        }
    }
}

int parent_to(int now, int dep) {
    if (depth[now] == dep) return now;

    int i(1), size(tree[now].size());
    for (; i < size; i++) {
        if (depth[ tree[now][i] ] < dep) break;
    }
    return parent_to(tree[now][i-1], dep);
}

int common(int a, int b) { // binary search
    int min_depth = min(depth[a], depth[b]);

    int low(1), high(min_depth);
    while (low < high) {
        int mid = (low + high + 1) >> 1;
        if (parent_to(a, mid) == parent_to(b, mid)) low = mid;
        else high = mid - 1;
    }

    return parent_to(a, high);
}

int mid_porint_of(int a, int b) {
    int c = common(a, b);
    if (depth[a] >= depth[b]) {
        int mid = (depth[a] - depth[b]+1)/2 + depth[c];
        return parent_to(a, mid);
    }
    else {
        int mid = (depth[b] - depth[a])/2 + depth[c];
        return parent_to(b, mid);
    }
}

void solve() {
    refine(1);
    while(k--) {
        int a, b;
        scanf("%d %d", &a, &b);
        cout << mid_porint_of(a, b) << endl; 
    }
}

void clear() {
    for (int i = 1; i <= n; i++) {
        in[i].clear();
        tree[i].clear();
    }
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        input();
        solve();
        clear();
    } 
    return 0;
}

