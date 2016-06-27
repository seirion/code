// 독재 왕국
#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

struct T {
    int d, c, r; // depth, cost, (reverse)
    vector<int> p; // parent
    T(int d_ = 0, int c_ = 0, int r_ = 0) : d(d_), c(c_), r(r_) {}
    bool operator <(const T &t) const { return d < t.d; }
};

int n, q;
T tree[100002];  // connection
int mm[100002]; // distance of (leaves - root)
int query[300002][2];
set<int> s;

void build_parent_list(int me, int parent, int jump/* power of 2 */) {
    if (jump < tree[parent].p.size()) {
        tree[me].p.push_back(tree[parent].p[jump]);
        build_parent_list(me, tree[parent].p[jump], jump+1);
    }
}

void input() {
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int p; cin >> p >> tree[i].c;
        tree[i].p.push_back(p);
        build_parent_list(i, p, 0);

        const T &parent = tree[p];
        tree[i].d = parent.d + 1;
        tree[i].c += parent.c;

        s.insert(i);
        s.erase(p);
    }
    int m = s.size();
    for (int i = 0; i < m; i++) cin >> mm[i];
    for (int i = 0; i < q; i++) cin >> query[i][0] >> query[i][1];
}

int get_parent_at(int me, int parent_at) {
    int diff = tree[me].d - parent_at;
    if (diff == 0) return me;

    if ((diff & (diff-1)) == 0) {
        return tree[me].p[__builtin_ctz(diff)];
    }

    int index = 0;
    while ((1 << index) < diff) index++;
    return get_parent_at(tree[me].p[index-1], parent_at);
}

int get_common(int a, int b) { // binary search
    int low(0), high(min(tree[a].d,tree[b].d));

    while (low < high) {
        int mid = (low + high + 1) >> 1;

        if (get_parent_at(a, mid) == get_parent_at(b, mid)) low = mid;
        else high = mid - 1;
    }

    return get_parent_at(a, high);
}

int distance(int from, int to) {
    int common = get_common(from, to);
    return tree[from].c + tree[to].c - 2 * tree[common].c;
}

void build_reverse() {
    int size = s.size();
    auto myless = [](int left, int right) { return tree[left] < tree[right]; };
    priority_queue<int, vector<int>, decltype(myless)> Q(myless);
    int i = 0;
    for (int x : s) {
        tree[x].r = mm[i++];
        Q.push(x);
    }

    while (!Q.empty()) {
        int index = Q.top(); Q.pop();
        if (index == 1) continue;
        T &now = tree[index];

        int parent = now.p[0];
        if (tree[parent].r == 0) {
            tree[parent].r = now.r + (now.c - tree[parent].c);
            Q.push(parent);
        } else {
            int cost = now.r + (now.c - tree[parent].c);
            tree[parent].r = min(tree[parent].r, cost);
        }
    }
}

int reverse_distance(int from, int to, int base) {
    int r = min(tree[from].c, tree[from].r) + min(tree[to].c, tree[to].r);
    return min(r, base);
}

void solve() {
    build_reverse();

    int r(0), rr(0);
    for (int i = 0; i < q; i++) {
        int base = distance(query[i][0], query[i][1]);
        r += base;
        rr += reverse_distance(query[i][0], query[i][1], base);
    }
    cout << r << " " << rr << endl;
}

void clear() {
    for (int i = 2; i <= n; i++) {
        tree[i].p.clear();
        tree[i].r = 0;
    }
    s.clear();
}

int main() {
    int t; cin >> t;
    while (t--) { input(); solve(); clear(); }
    return 0;
}
