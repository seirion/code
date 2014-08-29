// http://lgecodejam.com
// lge code jam August, 2014
// problem.1
// hyungyu.jang@lge.com


#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
    #include <trace/trace.h>
#else
    #define trace printf
#endif

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n, m;
int in [200 * 1000 + 1];

int check_path(int a, int b) {
    while (a != 1) {
        if (a == b) return 1;
        a = in[a];
    }
    return 0;
}

int check(int a, int b) {
    if (check_path(a, b)) return 1;
    if (check_path(b, a)) return 1;
    return 0;
}

void solve() {
    scanf("%d %d", &n, &m);

    int i, a, b;
    for (i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        in[b] = a;
    }

    for (i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        if (a == 1 || b == 1) {
            printf("1\n");
            continue;
        }
        printf("%d\n", check(a, b));
    }
}

int main(int, char*[]) {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {solve();}
    return 0;
}
