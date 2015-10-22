// http://algospot.com/judge/problem/read/CHRISTMAS
#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>

using namespace std;
typedef long long int64;
const int MOD = 20091101;

int n, k;
int in[100001] = {0, };
set<int> remain[100001];
int memo[100001];

void input() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
        in[i] = (in[i] + in[i-1]) % k;
    }

    for (int i = 0; i <= n; i++) {
        remain[in[i]].insert(i);
    }
}

int ways_to_buy() {
    int64 ways = 0;
    for (int i = 0; i < k; i++) {
        int64 s = remain[i].size();
        if (s >= 2) {
            ways += (s * (s-1)) / 2;
            ways %= MOD;
        }
    }
    return (int)ways;
}

int index_matching(int i, int index) {
    auto it = remain[i].find(index);
    if (it == remain[i].begin()) return -1;
    return *(--it);
}

int max_buy(int to) {
    int &result = memo[to];
    if (result != -1) return result;
    result = 0;

    int index = index_matching(in[to], to);
    if (index != -1) { // buy to'th one
        result = 1 + max_buy(index);
    }

    result = max(result, max_buy(to - 1));
    return result;
}

void solve() {
    memset(memo, 0xFF, sizeof(memo));
    memo[0] = 0;
    printf("%d %d\n", ways_to_buy(), max_buy(n));
}

void clear() {
    for (int i = 0; i < k; i++) remain[i].clear();
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {input(); solve(); clear();}
    return 0;
}
