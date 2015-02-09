// http://codeforces.com/contest/510/problem/A
// A. Fox And Snake
#include <cstdio>

using namespace std;

char snake[4][51] = {
    "##################################################",
    "..................................................",
    "##################################################",
    "#................................................."
};

int main() {
    int n, m;
    char sharp[51], dot[51];
    scanf("%d %d", &n, &m);
    snake[0][m] = snake[1][m] = snake[2][m] = snake[3][m] = 0;
    snake[1][m-1] = '#';
    for (int i = 0; i < n; i++) {
        printf("%s\n", snake[i%4]);
    }
    return 0;
}
