// 삼거리 주유소
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct T {
    T(int v_ = 0, int l_ = 0) : v(v_), l(l_) {}
    int v, l; // value, length
};

int row, col, inter; // intersection
vector<T> hor, ver; // horizontal, vertical

void input() {
    cin >> row;
    hor.resize(--row);
    int i;
    for (i = 0; i < row; i++) cin >> hor[i].v >> hor[i].l;

    cin >> inter >> col;
    inter--; // 0-based indexing

    ver.resize(++col);
    cin >> ver[0].l;
    for (i = 1; i < col-1; i++) cin >> ver[i].v >> ver[i].l;
    cin >> ver[i].v;
}

int push_pop(int limit) {
    stack<int> s;

    int i, r = 0;
    int currentv = hor[inter].v;
    for (i = 0; i < limit; i++) {
        currentv = min(currentv, ver[i].v);
        s.push(ver[i].l);
        r += currentv * ver[i].l;
    }
    currentv = min(currentv, ver[i].v);

    while (!s.empty()) {
        r += currentv * s.top();
        s.pop();
    }

    for (int i = inter; i < hor.size(); i++) {
        currentv = min(currentv, hor[i].v);
        r += currentv * hor[i].l;
    }

    return r;
}

void solve() {
    int currentv = hor[0].v;
    int prev = 0;
    int i;
    for (i = 0; i < inter; i++) {
        currentv = min(currentv, hor[i].v);
        prev += currentv * hor[i].l;
    }
    currentv = min(currentv, hor[i].v);
    ver[0].v = currentv;

    int r = 0x7FFFFFFF;
    for (int i = 0; i < ver.size(); i++) {
        r = min(r, push_pop(i));
    }

    cout << prev + r << endl;
}

void clear() {
    hor.clear(); ver.clear();
}

int main() {
    int t; cin >> t;
    while (t--) { input(); solve(); clear(); }
    return 0;
}
