// Problem2
// hyungyu.jang@lge.com

#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
    #include <code/debug.h>
#else
    #define trace printf
#endif

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>

using namespace std;

class Queues {
public:
    Queues(int q0, int q1) {q[0] = q0; q[1] = q1;}
    int q[2];
    bool operator<(const Queues &o) const {
        return q[0] == o.q[0] ? q[1] < o.q[1] : q[0] < o.q[0];
    }
};

///////////////////////////////////////////////////////////////////////
int n;
int Q[1000000][2];

void getInput() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &Q[i][0], &Q[i][1]);
    }
}


void solve() {
    int solution = max(Q[0][0], Q[0][1]);
    set<Queues> s0, s1;
    s0.insert(Queues(Q[0][0], Q[0][1]));

    for (int i = 1; i < n; i++) {
        int q0 = Q[i][0];
        int q1 = Q[i][1];
        set<Queues>::iterator it = s0.begin();
        int localMax = 0x7FFFFFFF;
        for (; it != s0.end(); it++) {
            if (it->q[0] == 0 && it->q[1] == 0) {
                s1.insert(Queues(q0, q1));
                localMax = min(localMax, max(q0, q1));
                continue;
            }
            if (it->q[0] > 0) {
                int v0 = q0 + it->q[0] - 1;
                int v1 = q1 + it->q[1];
                s1.insert(Queues(v0, v1));
                localMax = min(localMax, max(v0, v1));
            }
            if (it->q[1] > 0) {
                int v0 = q0 + it->q[0];
                int v1 = q1 + it->q[1] - 1;
                s1.insert(Queues(v0, v1));
                localMax = min(localMax, max(v0, v1));
            }
        }

        s0.clear();
        s0.swap(s1);

        solution = max(solution, localMax);
    }
    trace("%d\n", solution);
}

int main(int argc, char *argv[]) {
    getInput();
    solve();
    return 0;
}
