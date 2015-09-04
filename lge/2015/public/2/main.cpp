// LGE codejam 2015
// 2. 
#include <cstdio>
#include <iostream>
#include <set>
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
int bottom, top;
int _left, _right;
vector<Node> in;
multiset<Node, bool(*)(const Node&, const Node&)> mid(less_x);

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

void setup() {
    int to = n - k;
    auto it = in.begin(); advance(it, to);

    int i(0), upto(in[0].y + w);
    for (; i < to; i++) {
        if (upto < in[i].y) break;
    }
    bottom = i;

    int downto(in[to-1].y - w);
    for (; i < to; i++) {
        if (downto <= in[i].y) break;
        mid.insert(in[i]);
    }
    top = i;
}

bool only_x(const Node &a, const Node &b) { return a.x < b.x; }

void forward(int index) {
    int to = n - k + index;

    int i, downto(in[to-1].y - w);
    for (i = top; i < to; i++) {
        if (downto <= in[i].y) break;
        mid.insert(in[i]);
    }
    top = i;

    int upto(in[index].y + w);
    for (i = bottom; i < to; i++) {
        if (upto < in[i].y) break;
        mid.erase(in[i]);
        auto it = mid.find(in[i]);
        if (it != mid.end()) mid.erase(it);
    }
    bottom = i;
}

bool ok() {
    if (mid.empty()) return true;
    auto it = mid.upper_bound(Node(_left, 0x7FFFFFFF));

    return it == mid.end() || _right <= it->x;
}

bool possible() {
    sort(in.begin(), in.end(), less_y); 
    setup();
    for (int i = 0; i <= k; i++) { // check each query
        if (i) forward(i);
        if (ok()) return true;
    } 
    return false;
}

void clear() {
    in.clear();  mid.clear();
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
