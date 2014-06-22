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
#include <queue>
#include <functional>

using namespace std;
typedef long long int64;

enum { MANY = 0, ONE, }; // many solution, only one solution, not determined

class Line { public: // edge
    Line(int f, int t, int c): from(f), to(t), cost(c) {}
    bool operator >(const Line& l) const { 
        return cost > l.cost;
    }
    int from, to, cost;
};

int n, m, k;
int snum; // number of solutions
vector<Line> in[100 * 1000 + 1];// 1-based
vector<Line> back[100 * 1000 + 1];// (backup for checking another MST)
vector<Line> path;  // backup optimal path


void push(priority_queue<Line, vector<Line>, greater<Line> > &q, vector<Line> &v) {
    int size = v.size();
    for (int i = 0; i < size; i++) q.push(v[i]);
}

// prim's algorithm
int64 prim(int64 solution) {
    bool checked[100 * 1000 + 1] = {false,};
    checked[1] = true;
    int oknum = 1;
    priority_queue<Line, vector<Line>, greater<Line> > remain;
    push (remain, in[1]);

    while (oknum < n) { // for all vertics
        Line line = remain.top(); // min cost
        if (!checked[line.from] || !checked[line.to]) { // if choose
            int node = checked[line.from] ? line.to : line.from;
            push (remain, in[node]);
            solution += line.cost;
            checked[node] = true;
            oknum++;
            path.push_back(line); // save edges
        }
        else { // not choose
            remain.pop();
        }
    }
    return solution;
}

void recover() {
    for (int i = 1; i <= n; i++) {
        in[i] = back[i];
    }
}
void clear() {
    for (int i = 1; i <= n; i++) {
        back[i].clear();
    }
}

bool remove(const Line &line) {
    int from = line.from;
    int to = line.to;
    if (in[from].size() == 1 || in[to].size() == 1) return false; // need not try
    int i, s;
    s = in[from].size();
    for (i = 0; i < s; i++) {
        if (in[from][i].from == from && in[from][i].to == to) {
            in[from].erase(in[from].begin() + i);
            break;
        }
    }
    s = in[to].size();
    for (i = 0; i < s; i++) {
        if (in[to][i].from == from && in[to][i].to == to) {
            in[to].erase(in[to].begin() + i);
            break;
        }
    }
    return true;
}

void solve() {
    int i;
    // init
    snum = ONE;
    path.clear();
    int64 base = 0;

    //input
    scanf("%d %d %d", &n, &m, &k);
    int from, to, cost;
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &from, &to, &cost);
        base += cost;
        back[from].push_back(Line(from, to, -cost));
        back[to].push_back(Line(from, to, -cost));

    }
    for (i = 0; i < k; i++) {
        scanf("%d %d %d", &from, &to, &cost);
        back[from].push_back(Line(from, to, cost));
        back[to].push_back(Line(from, to, cost));
    }

    // solve
    recover();
    int64 solution = prim(base);

    // checking
    int size = path.size();
    for (i = 0; i < size; i++) {
        recover(); // restore original input
        if (!remove(path[i])) { // need not try
            continue;
        }
        if (solution == prim(base)) {
            snum = MANY;
            break;
        }
    }
    clear();
    trace("%lld %d\n", solution, snum);
}

int main(int, char*[]) {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {solve();}
    return 0;
}

