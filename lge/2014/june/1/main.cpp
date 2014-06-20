// http://lgecodejam.com
// lge code jam June, 2014
// problem.1
// hyungyu.jang@lge.com


#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
    #include <trace/trace.h>
#else
    #define trace printf
#endif

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int WORD = 0;
const int POS = 1;

class Input { public:
    Input(int w, int p) : word(w), pos(p) {}
    ~Input() {}
    int word, pos;
};

int n, k;
int count[1001];
int klist[1001];
int in[1000 * 1000 + 1][2];
int oknum; // ok if the value == k
int solution;

void solve() {
    int i, from, to;
    scanf("%d %d", &n, &k);
    for (i = 1; i <= k; i++) {
        scanf("%d", &klist[i]);
    }

    // 0. init
    memset(count, 0, sizeof(int) * 1001);
    oknum = from = to = 0;

    // 1. input
    for (i = 0; i < n; i++) {
        scanf("%d %d", &in[i][WORD], &in[i][POS]);
    }

    // find first solution
    from = in[WORD][POS];
    int sindex(0), tindex(0); // start & to index
    for (tindex = 0; tindex < n; tindex++) {
        int word = in[tindex][WORD];
        to = in[tindex][POS];
        if (++count[word] == klist[word]) { 
            if (++oknum == k) break;
        }
    }

    if (oknum == k) solution = to - from + 1;
    else {
        trace("-1\n");
        return;
    }

    // find better
    while (tindex < n) {
        if (oknum == k) {
            int word = in[sindex][WORD]; // word before (to be removed)
            sindex++;
            from = in[sindex][POS];
            if (--count[word] < klist[word]) { 
                oknum--;
            }
            else {
                solution = min(solution, to - from + 1);
            }
        }
        else {
            tindex++;
            if (tindex == n) break;
            int word = in[tindex][WORD];
            to = in[tindex][POS];
            if (++count[word] == klist[word]) { 
                if (++oknum == k) {
                    solution = min(solution, to - from + 1);
                }
            }
        }
    }

    trace("%d\n", solution);
}

int main(int, char*[]) {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {solve();}
    return 0;
}
