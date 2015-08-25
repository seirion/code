// LGE codejam 2015
// 2. 바빌로니아의 성벽 
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node { public:
    Node(int x_, int y_) : x(x_), y(y_) {}
    int x, y;
    bool operator==(const Node &n) const {
        return (x == n.x && y == n.y);
    }
};

bool less_x(const Node &a, const Node &b) { // x-major
    return (a.x == b.x ? a.y < b.y : a.x < b.x);
}

bool less_y(const Node &a, const Node &b) { // y-major
    return (a.y == b.y ? a.x < b.x : a.y < b.y);
}

int n, k, w;
int _left, _right;
vector<Node> in;

void input() {
    scanf("%d %d %d", &n, &k, &w);
    in.reserve(n);
    _left = 0x7FFFFFFF;
    _right = 0x80000000;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        in.push_back(Node(x, y));
        _left = min(_left, x);
        _right = max(_right, x);
    }
    _left += w;
    _right -= w;
}

bool only_x(const Node &a, const Node &b) { return a.x < b.x; }

bool ok(int from, int to) { // [from, to)
    int bottom = in[from].y + w;
    int top = in[to-1].y - w;

    for (int i = from; i < to; i++) {
        int x = in[i].x;
        int y = in[i].y;
        if (_left < x && x < _right && bottom < y && y < top) return false;
    }
    return true;
}

bool possible() {
    sort(in.begin(), in.end(), less_y); 

    int to = n-k;
    for (int i = 0; i <= k; i++, to++) { // check each query
        if (ok(i, to)) return true;
    } 
    return false;
}

void clear() {
    in.clear();
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        input();
        cout << (possible() ? "YES" : "NO") << endl;
        clear();
    } 
    return 0;
}
