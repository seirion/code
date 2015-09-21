// LGE codejam 2015
// 4. 메신져
#include <iostream>

using namespace std;
typedef long long int64;

class Point { public:
    Point (int64 x_ = 0, int64 y_ = 0) : x(x_), y(y_) {}
    int64 x, y;
    bool operator==(const Point &p) const {
        return x == p.x && y == p.y;
    }
    bool operator!=(const Point &p) const { return !operator==(p);}
};

int n;
Point from; // initial point of the prince
Point to[5001]; // points of the princess
int64 ab[5001], bb[5001]; // a->b, b->b

void input() {
    cin >> n; n++;
    cin >> from.x >> from.y;
    Point temp;
    for (int i = 1; i < n; i++) cin >> temp.x >> temp.y;
    for (int i = 0; i < n; i++) cin >> to[i].x >> to[i].y;
}

int64 distance(const Point &a, const Point &b) {
    return max(abs(a.x - b.x), abs(a.y - b.y));
}

int64 mid_point(int64 a, int64 b) { // closer to low(a)
    int64 distance = abs((a - b) / 2);
    return (a < b ? a + distance : a - distance);
}

Point mid_point(const Point &a, const Point &b) {
    return Point(mid_point(a.x, b.x), mid_point(a.y, b.y));
}

Point plus_one(const Point &a, const Point &b) {
    Point mid(a);
    if (a.x != b.x) mid.x += (a.x < b.x ? 1 : -1);
    if (a.y != b.y) mid.y += (a.y < b.y ? 1 : -1);
    return mid;
}

void solve() {
    ab[0] = distance(from, to[0]);
    bb[0] = 0;
    for (int i = 1; i < n; i++) {
        ab[i] = distance(from, to[i]);
        bb[i] = bb[i-1] + distance(to[i-1], to[i]);
    }

    int i = 0;
    while (ab[i] > bb[i] && i < n) { i++; }
    if (i == n) { cout << -1 << endl; return; }
    if (i == 0) { cout << 0 << endl; return; }

    Point low(to[i-1]), high(to[i]), mid; // (low, high]
    while (low != high) { // binary search
        mid = mid_point(low, high);
        if (distance(from, mid) > bb[i-1]+distance(to[i-1], mid)) low = plus_one(mid, high);
        else high = mid;
    }

    cout << bb[i-1]+distance(to[i-1], high) + 1 << endl;
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        input(); solve();
    } 
    return 0;
}
