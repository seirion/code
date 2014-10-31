// One-Based Arithmetic
// http://codeforces.com/problemset/problem/440/C
#include <cstdio>
#include <iostream>

using namespace std;
typedef unsigned long long uint64;

// 20 11111111111111111111
uint64 systems[21]; // 11-system

void build_system_number() {
    systems[1] = 1;
    int i = 2;
    for (;; i++) {
        systems[i] = systems[i-1] * 10 + 1;
        if (systems[i] < systems[i-1]) break; // overflow
    }
}

int count(uint64 in, bool expand) {
    if (in <= 6) return in;

    int i = 20;
    for (; i > 0; i--) {
        if (in >= systems[i]) break;
    }
    if (in == systems[i]) return i;

    int m = (int)(in / systems[i]);
    if (expand) {
        return min(
            (i + 1) + count(systems[i+1] - in, systems[i] > systems[i+1] - in),  // 111 - xx
            (i * m) + count(in - m * systems[i], true) // 11 + 11 + 11 + x
        );
    }
    else {
        return (i * m) + count(in - m * systems[i], true);
    }
}

int main() {
    build_system_number();
    uint64 i;
    scanf("%I64d", &i);
    printf("%d\n", count(i, true));
    return 0;
}
