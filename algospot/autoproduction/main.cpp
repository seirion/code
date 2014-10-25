// http://algospot.com/judge/problem/read/AUTOPRODUCTION
#include <cstdio>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>


using namespace std;

int n;
int all[10];
int in[10][10];
int size[10];

class Counter { public:
    Counter(int i_, int c_) : i(i_), c(c_) {}
    int i, c;
    bool operator >(const Counter& o) const {
        return (c == o.c ? i > o.i : c > o.c);
    }
};

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &all[i], &size[i]);
        for (int j = 0; j < size[i]; j++) {
            scanf("%d", &in[i][j]);
        }
    }
}

void solve() {
    priority_queue<Counter, vector<Counter>, greater<Counter> > pq;
    deque<int> dq[10];

    int i, j, limit(0);
    for (i = 0; i < n; i++) {
        pq.push(Counter(i, 0));
        sort(in[i], in[i] + size[i], greater<int>());

        dq[i].push_back(in[i][0] / all[i]);
        for (j = 1; j < size[i]; j++) {
            in[i][j] += in[i][j-1];
            dq[i].push_back(in[i][j] / all[i]);
        }
        limit += size[i];
    }

    limit = min(10, limit);
    for (i = 0; i < limit; i++) {
        Counter c = pq.top();
        if (dq[c.i].empty()) break;
        c.c = dq[c.i].front();
        dq[c.i].pop_front();

        pq.pop();
        pq.push(c);
    }

    printf("%d\n", pq.top().c);
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
