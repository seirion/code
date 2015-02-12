// http://algospot.com/judge/problem/read/CLEANER
#include <cstdio>

using namespace std;

#define VISIT(v, i) ((v) & (1LL << i))

typedef long long int64;

int n, m, total;
int room[6 * 6];

void input() {
    scanf("%d %d", &n, &m);
    int limit = n * m;
    for (int i = 0; i < limit; i++) {
        scanf("%d", &room[i]);
    }
}

void tour(int now, int time, int64 visit) {
    visit |= 1LL << now;

    if (now == n * m - 1) { // the last cell
        if (time == n * m - 1) { // complete !
            total++;
            return;
        }
        return;
    }

    if (room[now] != -1 && room[now] != time) return;

    int next;
    next = now - m;
    if (next >= 0 && !VISIT(visit, next)) { // up
        tour(next, time +1, visit);
    }

    next = now + m;
    if (next < n * m && !VISIT(visit, next)) { // down
        tour(next, time +1, visit);
    }

    next = now + 1;
    if (next % m != 0 && !VISIT(visit, next)) { // right
        tour(next, time +1, visit);
    }

    next = now - 1;
    if (now % m != 0 && !VISIT(visit, next)) { // left
        tour(next, time +1, visit);
    }
}

void solve() {
    total = 0;
    tour(0, 0, 0LL);
    printf("%d\n", total);
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
