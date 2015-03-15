// http://codeforces.com/contest/520/problem/B
// B. Two Buttons

#include <cstdio>

using namespace std;

void solve(int from, int to) {
    int count = 0;
    while (to > from) {
        if (to & 1) {
            to += 1; 
            count++;
        }
        else {
            to >>= 1;
            count++;
        }
    }
    printf("%d\n", from - to + count);
}

int main() {
    int from, to;
    scanf("%d %d", &from, &to);

    solve(from, to);
    return 0;
}
