// hyungyu.jang@lge.com
// 1-2

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXNUM = 1000 * 1000 * 1000;
enum { NOW = 0, PRE, SAME, };
enum { LEFT = 0, RIGHT, };
int size;

void solve() {
    int from(1), to, pre, now, check;
    scanf("%d %d", &to, &size);
    scanf("%d %d", &pre, &check);
    bool flag = false;
    for (int i = 1; i < size; i++) {
        scanf("%d %d", &now, &check);

        if (pre == now) {
            printf("%d ", to - from + 1);
            continue;
        }
        int small = min(pre, now);
        int large = max(pre, now);
        if (pre < now && check == NOW) check = RIGHT;
        else if (pre < now && check == PRE) check = LEFT;
        else if (pre > now && check == NOW) check = LEFT;
        else if (pre > now && check == PRE) check = RIGHT;

        if (check == RIGHT) {
            from = max(from, ((small + large) / 2) + 1);
        }
        else if (check == LEFT) {
            to = min(to, (small + large - 1) / 2);
        }
        else {
            to = from = (small + large) / 2;
            flag = true;
        }

        printf("%d ", to - from + 1);
        pre = now;
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) { solve(); }
    return 0;
}

