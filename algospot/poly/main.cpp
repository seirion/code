// http://algospot.com/judge/problem/read/POLY
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long int64;
const int DEVIDER = 10000000;

int memo [101][101];

int count(int all, int line1) {
    if (all == line1) return 1;
    int &sum = memo[all][line1];
    if (sum != 0) return sum;

    for (int line2 = 1; line2 <= all - line1; line2++) {
        int m = (line1 + line2 - 1) * count(all - line1, line2) % DEVIDER;
        sum = (m + sum) % DEVIDER;
    }
    return sum % DEVIDER;
}

void solve() {
    int n;
    scanf("%d", &n);
    memset(memo, 0, sizeof(int) * 101 * 101);

    int sum = 0;
    for (int line1 = 1; line1 <= n; line1++) {
        int m = count(n, line1) % DEVIDER;
        sum = (m + sum) % DEVIDER;
    }
    printf("%d\n", sum);
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) { solve();}
    return 0;
}
