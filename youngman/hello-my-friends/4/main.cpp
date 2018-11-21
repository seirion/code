#include <cstdio>
//#include <fstream>
#include <map>
#include <cstring>

using namespace std;

const int SIZE = 500000 + 2;
int in[SIZE];
int n, k, q;
map<pair<int, int>, int> m; // input caching
int latest[SIZE] = {0, }; // input order set latest
int query[SIZE][2]; // input caching

class Tree {
public:
    Tree() { memset(tree, 0, sizeof(tree)); }
    int num(int x) { // [1, x]
        int s(0);
        while (x) {
            s += tree[x];
            x &= x - 1;
        }
        return s;
    }

    int update(int x, int delta = 1) {
        while (x <= k) {
            tree[x] += delta;
            x += -x&x;
        }
        return 0;
    }
private:
    int tree[SIZE] = {0, }; // binary indexed tree
};

Tree t1, t2;

void input() {
    scanf("%d %d", &n, &k);
    k++;
    for (int i = 1; i <= n; i++) { scanf("%d", &in[i]); in[i]++; } // 1-based indexing
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &query[i][0], &query[i][1]);
        query[i][1]++; // 1-based indexing
        m[make_pair(query[i][0], query[i][1])] = 0;
    }
}

void setLatest(int input, int index) {
    if (latest[input] != 0) {
        t2.update(latest[input], -1); // reset
    }
    latest[input] = index;
    t2.update(index);
}

int get(int index) {
    if (latest[index] == 0) return index - 1 + t1.num(k) - t1.num(index);
    else return t2.num(k) - t2.num(latest[index]);
}

void solve() {
    auto it = m.begin();
    for (int i = 1; i <= n && it != m.end(); i++) {
        const int &input = in[i];
        if (latest[input] == 0) t1.update(input);
        setLatest(input, i);

        while (it != m.end() && it->first.first == i) {
            it->second = get(it->first.second);
            it++;
        }
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", m[make_pair(query[i][0],query[i][1])]);
    }
}

//#define _TEST
int main() {
#ifdef _TEST
    std::ifstream in("/Users/babo/build/cpp/easy/input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    input();
    solve();
    return 0;
}
