// http://lgecodejam.com
// lge code jam August, 2014
// problem.2
// hyungyu.jang@lge.com


#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
    #include <trace/trace.h>
#else
    #define trace printf
#endif

#include <cstdio>
#include <cstring>

using namespace std;
int n;
int in1 [100 * 1000 + 1];
int in2 [100 * 1000 + 1];

// return (in1 < in2);
int less(int index, int start, int target, int mid) {
    if (in2[index] == mid) return 0;
    if (in1[index] == start && in2[index] == target) return 1;
    if (in1[index] == start) return less(index-1, start, mid, target);
    if (in1[index] == target) return less(index-1, mid, target, start);

    // something wrong
    printf("=================\n");
    return 0;
}

void solve() {
    int i, a;
    scanf("%d", &n);
    for (i = n; i > 0; i--) {
        scanf("%d", &a);
        in1[i] = a;
    }
    for (i = n; i > 0; i--) {
        scanf("%d", &a);
        in2[i] = a;
    }

    printf("%d\n", less(n, 1, 2, 3));
}

int main(int, char*[]) {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {solve();}
    return 0;
}
