// http://algospot.com/judge/problem/read/NPOLY
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long int64;
const int64 DEVIDER = 20090711;
int64 count_sym(int all, int line1);
 
int64 memo [101][101];
int64 sym [101][101];
 
int64 count_sym(int all, int line1) {
    if (all == line1 || all == line1 * 2) return 1;
    int64 &sum = sym[all][line1];
    if (sum != -1) return sum;

    sum = 0;
    int limit = (all - (line1 << 1));
    for (int line2 = 1; line2 <= limit; line2++) {
        int64 m = (line1 + line2 - 1) * count_sym(limit, line2) % DEVIDER;
        sum = (m + sum) % DEVIDER;
    }
    return sum;
}
 
int64 count(int all, int line1) {
    if (all == line1) return 1;
    int64 &sum = memo[all][line1];
    if (sum != 0) return sum;

    int limit = all - line1;
    for (int line2 = 1; line2 <= limit; line2++) {
        int64 m = (line1 + line2 - 1) * count(limit, line2) % DEVIDER;
        sum = (m + sum) % DEVIDER;
    }
    return sum;
}

void solve() {
    int n;
    scanf("%d", &n);
    memset(memo, 0, sizeof(int64) * 101 * 101);
    memset(sym, 0xFF, sizeof(int64) * 101 * 101);
 
    int64 sum(0), sym_sum(0);
    for (int line1 = 1; line1 < n; line1++) {
        int64 m = count(n, line1) % DEVIDER;
        sum = (m + sum) % DEVIDER;
        int64 s = count_sym(n, line1) % DEVIDER;
        sym_sum = (s + sym_sum) % DEVIDER;
    }
    printf("%lld\n", (sum - sym_sum + DEVIDER) % DEVIDER);
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) { solve();}
    return 0;
}
