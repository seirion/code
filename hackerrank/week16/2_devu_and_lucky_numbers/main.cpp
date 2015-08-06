// https://www.hackerrank.com/contests/w16/challenges/devu-and-lucky-numbers
// Devu and Lucky Numbers
#include <iostream>
#include <cstring>

using namespace std;

typedef long long int64;
const int64 MOD = 1000000007LL;

int64 memo[101][101][101];
int64 ncases[101][101][101];

void init() {
    memset(memo, 0xFF, sizeof(memo));
    memset(ncases, 0xFF, sizeof(ncases));
    memo[0][0][0] = 0;
    ncases[0][0][0] = 1;
}

int64 cases(int x, int y, int z) { // number of cases
    int64 &r = ncases[x][y][z];
    if (r == -1) {
        r = 0;
        if (x > 0) r += cases(x-1, y, z);
        if (y > 0) r += cases(x, y-1, z);
        if (z > 0) r += cases(x, y, z-1);
        r = r % MOD;
    }
    return r;
}

int64 sum_(int x, int y, int z) { // sum of all numbers
    int64 &r = memo[x][y][z];
    if (r == -1) {
        r = 0;
        if (x > 0) r += sum_(x-1, y, z) * 10 + 4 * cases(x-1, y, z);
        if (y > 0) r += sum_(x, y-1, z) * 10 + 5 * cases(x, y-1, z);
        if (z > 0) r += sum_(x, y, z-1) * 10 + 6 * cases(x, y, z-1);
        r = r % MOD;
    }
    return r;
}

int64 sum_of_all(int x, int y, int z) {
    int64 sum = 0;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            for (int k = 0; k <= z; k++) {
                sum += sum_(i, j, k);
            }
        }
    }
    return sum % MOD;
}

int main() {
    init();
    int x, y, z;
    cin >> x >> y >> z;
    cout << sum_of_all(x, y, z) << endl;

    return 0;
}
