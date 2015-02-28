// http://codeforces.com/contest/519/problem/C
// C. A and B and Team Training
#include <cstdio>
#include <iostream>


using namespace std;

int calc(int a, int b) {
    if (a > b * 2) {
        return b;
    }
    return (a + b) / 3;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n", calc(max(a,b), min(a,b)));
    return 0;
}
