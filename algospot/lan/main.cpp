// http://algospot.com/judge/problem/read/LAN
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

class Point { public:
    Point() {}
    int x, y;
};

class Line { public:
    Line(int f_, int t_, int d_) : from(f_), to(t_), d(d_) {}
    int from, to, d;
    bool operator >(const Line& l) const {
        if (d == l.d) {
            if (from == l.from) return to > l.to;
            return from > l.from;
        }
        return d > l.d;
    }
};

int size, m;
Point point[500];
bool established[500][500];
bool selected[500];
int info[500];
priority_queue<Line, vector<Line>, greater<Line> > Q;

int distance_square(int from, int to) {
    return (point[from].x - point[to].x) * (point[from].x - point[to].x) +
        (point[from].y - point[to].y) * (point[from].y - point[to].y);
}

void build_distance() {
    for (int from = 0; from < size; from++) {
        for (int to = from + 1; to < size; to++) {
            if (from == to) continue;
            if (established[from][to]) {
                Q.push(Line(from, to, 0));
            }
            else {
                Q.push(Line(from, to, distance_square(from, to)));
            }
        }
    }
}

void input() {
    memset(selected, 0, sizeof(bool) * 500);
    memset(established, 0, sizeof(bool) * 500 * 500);
    memset(info, 0xFF, sizeof(int) * 500); // -1
    //Q = priority_queue<Line, vector<Line>, greater<Line> >();

    scanf("%d %d", &size, &m);
    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", &point[i].x);
    }
    for (i = 0; i < size; i++) {
        scanf("%d", &point[i].y);
    }
    for (i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        established[a][b] = established[b][a] = true;
    }
    build_distance();
}

bool circular(int a, int b) {
    while (a != -1 && b != -1) {
        if (a == b) return true;
        if (a > b) {
            a = info[a];
        }
        else {
            b = info[b];
        }
    }
    return false;
}

bool available(const Line& line) {
    if (circular(line.from, line.to)) return false;
    return true;
}

void connect(int from, int to) {
    if (info[to] == -1) {
        info[to] = from;
        return;
    }

    while (info[from] != -1) {
        from = info[from];
    }
    while (info[to] != -1) {
        to = info[to];
    }

    if (from < to) {
        info[to] = from;
    }
    else {
        info[from] = to;
    }
}

// kruskal
void solve() {
    selected[0] = true;
    double cost = 0.0;

    while (!Q.empty()) {
        Line line = Q.top();
        if (available(line)) {
            connect(line.from, line.to);
            //info[line.to] = line.from; // connect
            cost += sqrt(line.d);
        }
        Q.pop();
    }

    printf("%.9f\n", cost);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) { input(); solve(); }
    return 0;
}
