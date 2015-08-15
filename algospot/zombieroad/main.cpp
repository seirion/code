// http://algospot.com/judge/problem/read/ZOMBIEROAD
#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using namespace std;

int n = 0;
set<int> in[20001];
map<pair<int, int>, bool> zomb;
int nh[20001]; // # hunman child

void input() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        in[a].insert(b);
        in[b].insert(a);
        zomb[make_pair(a, b)] = zomb[make_pair(b, a)] = (d == 1);
    }
}

void clear() {
    memset(nh, 0, sizeof(nh));
    for (int i = 0; i <= n; i++) {
        in[i].clear();
    }
    zomb.clear();
}


int nhuman(int parent) { // count human child
    if (in[parent].empty()) { // leaf node
        return nh[parent]; // 0
    }

    for (auto child : in[parent]) { // for each child
        in[child].erase(parent); // remove parent from children list
        if (nhuman(child) > 0 || !zomb[make_pair(parent, child)]) nh[parent]++;
    }
    return nh[parent];
}

int all(int parent, bool force) {
    int c = 0;
    for (auto child : in[parent]) { // for each child
        if (nh[child] == 0) continue;

        bool iszomb = zomb[make_pair(parent, child)];

        if (iszomb) {
            if (force || nh[parent] >= 2) c++;
        }
        c += all(child, force || !iszomb || nh[parent] >= 2);
    }
    return c;
}

void solve() {
    nhuman(0);
    printf("%d\n", all(0, false));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) { clear(); input(); solve();}
    return 0;
}
