// http://algospot.com/judge/problem/read/MAGICPOWER
#include <cstdio>
#include <queue>

using namespace std;

int in[100];

void solve() {
    int n, m, i, t;
    priority_queue<int> Q;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        Q.push(t);
    }
    int sum = 0;
    for (int i = 0; i < m && !Q.empty(); i++) {
        t = Q.top();
        Q.pop();
        sum += t;
        if (t > 1) {
            Q.push(t-1);
        }
    }
    printf("%d\n", sum);
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {solve();}
    return 0;
}
