// 유적지
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class P;
int n;
vector<P> in;

struct P {
    P(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
    int x, y;
};

P base;

P operator -(const P &a, const P &b) { return P(a.x - b.x, a.y - b.y); }
bool is_left(const P& a, const P& b) { return 0 < a.x*b.y - a.y*b.x; } // cross product
bool comp(const P& a, const P& b) { return a.y == b.y ? a.x < b.x : a.y < b.y; } // y 값이 작게
bool comp2(const P& a, const P& b) { return is_left(a - base, b - base); }
double distance(const P &a, const P &b) { return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)); }


int find(const P &p) {
    for (int i = 0; i < n; i++) {
        if (in[i].x == p.x && in[i].y == p.y) return i;
    }
    return -1;
}

double convex_hull(vector<P> &v) {
    if (v.size() <= 1) return .0;
    if (v.size() == 2) return distance(v[0], v[1]) * 2;

    auto it = min_element(v.begin(), v.end(), comp);
    if (v.begin() != it) iter_swap(v.begin(), it);
    base = v.front();
    sort(v.begin() + 1, v.end(), comp2);

    vector<P> out;
    out.push_back(v[0]);
    out.push_back(v[1]);
    for (int i = 2, size = v.size(); i < size; ) {
        P a(out[out.size()-2]), b(out[out.size()-1]);
        if (is_left(b - a, v[i] - a)) {
            a = b;
            out.push_back(v[i]);
            i++;
        }
        else {
            out.pop_back();
        }
    }

    double r = distance(out.front(), out.back());
    for (int i = 1, size = out.size(); i < size; i++) r += distance(out[i], out[i-1]);
    return r;
}

double each(int a, int b) {
    vector<P> left, right;
    left.push_back(in[a]);
    left.push_back(in[b]);

    P ab = in[b] - in[a];
    for (int i = 0; i < n; i++) {
        if (i == a || i == b) continue;
        if (is_left(ab, in[i] - in[a])) left.push_back(in[i]);
        else right.push_back(in[i]);
    }
    return convex_hull(left) + convex_hull(right);
}

void input() {
    cin >> n;
    in.resize(n);
    for (int i = 0; i < n; i++) cin >> in[i].x >> in[i].y;
}

void solve() {
    double r = 1e10;
    for (int a = 0; a < n; a++) for (int b = 0; b < n; b++) r = min(r, each(a, b));
    printf("%.5f\n", r);
}

int main() {
    int t; cin >> t;
    while (t--) { input(); solve(); }
    return 0;
}
