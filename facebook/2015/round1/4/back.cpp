// https://www.facebook.com/hackercup/problems.php?pid=759650454070547&round=344496159068801
// Facebook Hacker Cup 2015 Round 1
// 4. Corporate Gifting
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Tree { public:
    Tree() : id(0), pid(0) {}
    //Tree(int i, int p) : id(i), pid(p) {}
    int id, pid;
    vector<int> child;
    void clear() { child.clear(); }
};

Tree tree[200*1000 + 1];
int memo[200*1000 + 1][3]; // 0 1 2

void clear(int n) {
    for (int i = 1; i <= n; i++) {
        tree[i].clear();
    }
}

int dfs(int id, int value) { // depth-first-search
    int &cost = memo[id][value];
    if (cost != 0) return cost;
    cost = (value == 0 ? 3 : value);

    // child shoud be {1,2,3} - {value}
    vector<int> &child = tree[id].child;
    int size = child.size();
    for (int i = 0; i < size; i++) {
        cost += min(
                dfs(child[i], (value+1) % 3),
                dfs(child[i], (value+2) % 3)
                );
    }
    return cost;
}

void solve() {
    memset(memo, 0, sizeof(int) * (200 * 1000 + 1) * 3);

    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        int pid; // pid
        scanf("%d\n", &pid);
        Tree &now = tree[i];
        now.id = i;
        now.pid = pid;
        tree[pid].child.push_back(i);
    }

    /////////////////////////////////////////////////////////////////////////
    int mini = 0x7FFFFFFF;
    for (int i = 0; i < 3; i++) {
        mini = min(mini, dfs(1, i));
    }
    printf("%d\n", mini);
    clear(n);
}

int main() {
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}

