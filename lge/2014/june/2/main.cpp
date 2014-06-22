// http://lgecodejam.com
// lge code jam June, 2014
// problem.2
// hyungyu.jang@lge.com


#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
    #include <trace/trace.h>
#else
    #define trace printf
#endif

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using namespace std;
typedef unsigned long long uint64;

enum { MANY = 0, ONE, ND, }; // many solution, only one solution, not determined

class Line { public: // edge
    Line(int f, int t, int c): from(f), to(t), cost(c) {}
    bool operator <(const Line& l) const { 
        if (cost == l.cost) {
            if (from == l.from) return to < l.to;
            return from < l.from;
        }
        else return cost < l.cost;
    }
    int from, to, cost;
};

int n, m, k;
uint64 solution;
int snum; // number of solutions
bool checked[100 * 1000 + 1];
vector<Line> in[100 * 1000 + 1];// 1-based


// prim's algorithm
void prim() {
    checked[1] = true;
    int oknum = 1;
    set<Line> remain;
    remain.insert(in[1].begin(), in[1].end());
    in[1].clear();

    while (oknum < n) { // for all vertics
        while (true) {
            Line line = *remain.begin(); // min cost
            if (!checked[line.from] || !checked[line.to]) { // if choose
                int node = checked[line.from] ? line.to : line.from;
                remain.insert(in[node].begin(), in[node].end());
                in[node].clear();
                solution += line.cost;
                remain.erase(line);
                checked[node] = true;
                oknum++;
                break;
            }
            else { // not choose
                remain.erase(remain.begin());
            }
        }
    }
}


void solve() {
    int i;
    // init
    solution = 0;
    snum = ND;
    memset(checked, 0, sizeof(bool) * (100 * 1000 + 1));

    //input
    scanf("%d %d %d", &n, &m, &k);
    int from, to, cost;
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &from, &to, &cost);
        solution += cost;
        in[from].push_back(Line(from, to, -cost));
        in[to].push_back(Line(from, to, -cost));

    }
    for (i = 0; i < k; i++) {
        scanf("%d %d %d", &from, &to, &cost);
        in[from].push_back(Line(from, to, cost));
        in[to].push_back(Line(from, to, cost));
    }

    // solve
    prim();
    trace("%d %d\n", solution, snum);
}

int main(int, char*[]) {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {solve();}
    return 0;
}

