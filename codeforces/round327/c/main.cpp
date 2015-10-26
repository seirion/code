// http://codeforces.com/contest/591/problem/C
#include <cstdio>
#include <iostream>

using namespace std;

int n;
char in[500002];

void input() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) scanf("%c ", &in[i]);
}

void set(int from, int to) { // [from, to)
    char x = in[from-1];
    char y = in[to--];
    
    while (from <= to) {
        in[from++] = x;
        in[to--] = y;
    }
}

void solve() {
    int best(0), begin(1), count(0), i;
    bool zigzag = false;
    for (i = 1; i < n-1; i++) {
        if (in[i-1] != in[i] && in[i] != in[i+1]) {
            if (zigzag) continue;
            begin = i;
            zigzag = true;
        }
        else {
            if (zigzag) {
                set(begin, i);
                best = max(best, (i-begin+1)/2);
            }
            zigzag = false;
        }
    }
    if (zigzag) {
        set(begin, i);
        best = max(best, (i-begin+1)/2);
    }

    printf("%d\n", best);
    for (i = 0; i < n; i++) {
        printf("%c ", in[i]);
    }
    printf("\n");
}

int main() {
    input();
    solve();   
    return 0;
}
