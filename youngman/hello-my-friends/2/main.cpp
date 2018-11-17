#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class T { public:
    //T(int index) : i(index) {}
    int i, p, num, depth;
    vector<int> child;
};
int n, m;
T tree[1000001];
bool leaf[1000001];

void input() {
    memset(leaf, 0xff, sizeof(leaf));
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        tree[i].i = i;
        cin >> tree[i].p;
        tree[tree[i].p].child.push_back(i);
        leaf[tree[i].p] = false;
    }
}

void build(T& parent) {
    for (int i = 0; i < n; i++) {
        if (!leaf[i]) continue;

        T *now = &tree[i];
        now->depth = 1;
        while (now->i != 0) {
            T *p = &tree[now->p];
            p->depth = now->depth + 1;
            now = p;
        }
    }
}

int go(int index) {
    T &now = tree[index];
    vector<int> v;
    for (int i : now.child) {
        go(i);
        v.push_back(tree[i].num);
    }
    sort(v.begin(), v.end(), greater<int>());

    int limit = index == 0 ? m : m - 1;
    limit = min(limit, (int) now.child.size());
    now.num = 1;
    for (int i = 0; i < limit; i++) {
        now.num += v[i];
    }
    return now.num;
}

int solve() {
    if (m == 1) { return 1; }
    // dfs
    return go(0);
}

int main() {
    //std::ifstream in("/Users/babo/build/cpp/easy/input.txt");
    //std::cin.rdbuf(in.rdbuf());
    input();
    build(tree[0]);
    cout << solve() << endl;
    return 0;
}
