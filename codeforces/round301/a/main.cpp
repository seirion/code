// http://codeforces.com/contest/540/problem/A
// A. Combination Lock
#include <cstdio>
#include <cstdlib> // abs

using namespace std;

char in1[1002];
char in2[1002];

int main() {
    int n;
    scanf("%d\n", &n);
    fgets(in1, 1002, stdin);
    fgets(in2, 1002, stdin);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int diff = abs(in1[i] - in2[i]);
        if (diff > 5) sum += (10 - diff);
        else sum += diff;
    }

    printf("%d\n", sum);
    return 0;
}
