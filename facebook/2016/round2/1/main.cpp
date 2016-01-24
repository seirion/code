// Facebook Hacker Cup 2016 Round 2
// Boomerang Decoration
// https://www.facebook.com/hackercup/problem/424794494381569/
#include <iostream>
#include <cstdio>

using namespace std;

int n;
char a[100005];
char b[100005];

int ccc[100005];

void input() {
    scanf("%d\n", &n);
    fgets(a, sizeof(a), stdin);
    fgets(b, sizeof(b), stdin);
}

void solve(int k) {
    int result = 0x7FFFFFFF;

    ccc[0] = 1;
    for (int i = 1; i < n; i++) {
        if (b[i-1] == b[i]) ccc[i] = ccc[i-1];
        else ccc[i] = ccc[i-1] + 1;
    }

    int left, right;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (i == 0) left = 0;
            else left = ccc[i-1];

            while (a[i] == b[i] && i < n) i++;
            if (i == n) right = 0;
            else right = ccc[n-1] - ccc[i] + 1;

            result = min(result, max(left, right));
        }
    }
    result = min(result, (ccc[n-1]+1) / 2);


    printf("Case #%d: %d\n", k, result);
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        input();
        solve(i);
    }

    return 0;
}
