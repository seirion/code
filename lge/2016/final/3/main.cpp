//
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

struct P {
    P(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
    int x, y;
};

P operator -(const P &a, const P &b) { return P(a.x - b.x, a.y - b.y); }
int cross(const P& a, const P& b) { return a.x*b.y - a.y*b.x; } // cross product
bool is_left(const P& a, const P& b) { return 0 < cross(a, b); } // cross product
bool is_right(const P& a, const P& b) { return cross(a, b) < 0; } // cross product
double theta(const P &a) { return atan2(a.y, a.x); }

int n;
P in[200];
double aaa[200][200]; // a->b : b-a
double angle[200][200][200];
double best;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i].x >> in[i].y;
}

void build() {
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (a == b) continue;
            aaa[a][b] = theta(in[b] - in[a]);
        }
    }

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (a == b) continue;
            for (int c = 0; c < n; c++) {
                if (a == c || b == c) continue;
                angle[a][b][c] = aaa[a][b] - aaa[a][c];
                
                if (M_PI < angle[a][b][c]) angle[a][b][c] -= M_PI*2;
                if (angle[a][b][c] < -M_PI) angle[a][b][c] += M_PI*2;
            }
        }
    }
}

bool convex(int a, int b, int x, int y) { // x : left , y : right
    return 0 < angle[a][x][y] && angle[a][x][y] < M_PI &&
           0 < angle[b][y][x] && angle[b][y][x] < M_PI;
}

double area_triangle(int a, int b, int c) {
    return abs((double)(in[a].x * in[b].y +
                in[b].x * in[c].y +
                in[c].x * in[a].y -
                in[a].x * in[c].y -
                in[c].x * in[b].y -
                in[b].x * in[a].y) / 2);
}

double area(int a, int b, int x, int y) {
    return area_triangle(a, b, x) + area_triangle(a, b, y);
}

void check(int a, int b) {
    vector<int> left, right;
    P p = in[b] - in[a];
    for (int i = 0; i < n; i++) {
        if (i == a || i == b) continue;
        P x = in[i] - in[a];
        if (is_left(p, x)) left.push_back(i);
        else if (is_right(p, x)) right.push_back(i);
    }

    for (int x : left) {
        for (int y : right) {
            if (convex(a, b, x, y)) best = min(best, area(a, b, x, y));
        }
    }
}

void solve() {
    build();
    best = 20001.0 * 20001;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (a != b) check(a, b);
        }
    }
    printf("%.1f\n", best);
}

int main() {
    int t; cin >> t;
    while (t--) { input(); solve(); }
    return 0;
}
