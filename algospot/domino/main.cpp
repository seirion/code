// http://algospot.com/judge/problem/read/POLY
#include <cstdio>

using namespace std;

int memo [1001];


int count(int dot) {
    int count = dot * (dot+1) / 2;
    return count + dot * (dot+1);
}

int main() {
    int n;
    scanf("%d", &n);
    memo[1] = 3;
    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i-1] + count(i);
    }

    printf("%d\n", memo[n]);
    return 0;
}
