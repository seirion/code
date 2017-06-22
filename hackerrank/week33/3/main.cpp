#include <iostream>
#include <cstring>

using namespace std;

int n, k, m;
int in[100001];
int out[1000];
int mm[1001][1001] = {0, };

void swap(int &a, int &b) {
    int t = b; b = a; a = t;
}

int parent(int x) {
    if (in[x] == -1) return x;
    in[x] = parent(in[x]);
    return in[x];
}

void merge(int a, int b) {
    int x = parent(a);
    int y = parent(b);
    if (x == y) return;
    if (b < a) swap(a, b);
    in[y] = x;
}

bool same(int a, int b) {
    return parent(a) == parent(b);
}

int main() {
    memset(in, 0xFF, sizeof(in));
    cin >> n >> k >> m;
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        if (b < a) swap(a, b);
        merge(a, b);
    }

    for (int i = 0; i < m; i++) cin >> out[i];

    for (int i = 0; i < m; i++) mm[i][i] = 1;

    for (int len = 2; len <= m; len++) {
        int from = 0; int to = len - 1; // [from, to]
        for (; to < m; from++, to++) {
            if (same(out[from], out[to])) {
                if (from + 1 == to) mm[from][to] = 2;
                else mm[from][to] = 2 + mm[from+1][to-1];
            } else {
                mm[from][to] = max(mm[from+1][to], mm[from][to-1]);
            }
        }
    }

    cout << mm[0][m-1] << endl;

    return 0;
}
