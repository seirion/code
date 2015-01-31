// http://codeforces.com/contest/509/problem/0
// A. Maximum in Table
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int in[10][10] = {1,};

int main() {
    int i;
    for (i = 0; i < 10; i++) {
        in[i][0] = in[0][i] = 1;
    }
    for (i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            in[i][j] = in[i-1][j] + in[i][j-1];
        }
    }
    int n;
    scanf("%d", &n);
    printf("%d\n", in[n-1][n-1]);
    return 0;
}
