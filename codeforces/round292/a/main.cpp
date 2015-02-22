// http://codeforces.com/contest/515/problem/A
// A. Drazil and Date
#include <cstdio>
#include <queue>

using namespace std;

bool possible(int x, int y, int step) {
    x = x > 0 ? x : -x;
    y = y > 0 ? y : -y;

    if (step < x + y) return false;
    step = step - x - y;
    return (step % 2) == 0;
}

int main() {
    int x, y, step;
    scanf("%d %d %d", &x, &y, &step);

    printf("%s\n", possible(x, y, step) ? "Yes" : "No");
    return 0;
}
