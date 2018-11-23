#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

const int SIZE = 1000000 + 2;
int n, q;
vector<int> in[SIZE]; // connected
int v[SIZE] = {0, }; // keep values
int inputc[SIZE]; // input cache
int query[500000][2]; // index - value
bool exist[SIZE] = {false, };

// for fast skip
int maxOne = 0;
bool major[SIZE] = {false, }; // major party

void input() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d", &inputc[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &query[i][0], &query[i][1]);
        exist[query[i][0]] = true;
    }

    for (int i = 1; i < n; i++) {
        if (exist[i] && exist[inputc[i]]) {
            in[i].push_back(inputc[i]);
            in[inputc[i]].push_back(i);
        }
    }

    // for fast skip
    for (int i = 1; i < n; i++) {
        if (in[maxOne].size() < in[i].size()) maxOne = i;
    }
    for (const int &i : in[maxOne]) major[i] = true;
}

void solve() {
    int acc = 0; // for fast skip
    for (int i = 0; i < q; i++) {
        const int &u = query[i][0];
        const int &x = query[i][1];

        if (u == maxOne) { // check fast skip
            acc += x;
            printf("%d\n", v[u]);
            continue;
        }
        int r = v[u] + (major[u] ? acc : 0);
        printf("%d\n", r);
        for (const int &c: in[u]) {
            v[c] += x;
        }
    }
}

int main() {
    input();
    solve();
    return 0;
}
