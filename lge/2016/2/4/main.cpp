// 유적지
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double LEN[200][200];
double ATAN[200][200];

class P;
int n;
vector<P> in;

struct P {
    P(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
    int x, y;
    bool operator <(const P &p) const {
        P &z = in[0];
        return atan((double)(y - z.y) / (x - z.x)) < atan((double)(p.y - z.y) / (p.x - z.x));
    }
};

void input() {
    cin >> n;
    in.resize(n);
    for (int i = 0; i < n; i++) cin >> in[i].x >> in[i].y;
}

bool comp(const P& a, const P& b) { // y 값이 더 작은 순서
    return a.y == b.y ? a.x < b.x : a.y < b.y;
}

bool ok(const P& a, const P& b, const P& c) { return 0 < a.x*b.y - a.y*b.x; } // cross product

double get_exclude_one(int index) {
    vector<P> v;
    for (int i = 0; i < n; i++) if (i != index) v.push_back(in[i]);
    auto it = min_element(v.begin(), v.end(), comp);
    if (v.begin() != it) iter_swap(v.begin(), it);
    sort(v.begin() + 1, v.end());

    vector<P> out;
    out.push_back(v[0]);
    P one(v[0]), two;
    for (int i = 1, size = v.size(); i < size; i++) {
        if (ok()) { out.push_back(one); one = two; two = v[i]; }
        else { two = v[i]; }
    }
}

void solve() {
    double r = get_exclude_one(0);
    for (int i = 1; i < n; i++) r = min(r, get_exclude_one(i));
}

int main() {
    int t; cin >> t;
    while (t--) { input(); solve(); }
    return 0;
}
