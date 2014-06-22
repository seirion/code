// http://lgecodejam.com
// lge code jam June, 2014
// problem.3
// hyungyu.jang@lge.com


#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
    #include <trace/trace.h>
#else
    #define trace printf
#endif
#ifdef WIN32
    #include <intrin.h>
    #define popcount(x) __popcnt(x)
#else
    #define popcount(x) __builtin_popcount(x)
#endif

#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <functional>

using namespace std;

enum { X = 0, Y, }; // for indexing
typedef unsigned int uint32;

class Point { public:
    Point() : x(0), y(0) {}
    Point(int x_, int y_) : x(x_), y(y_) {}
    ~Point() {}
    bool operator <(const Point& p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
    bool operator >(const Point& p) const { // trick
        return y == p.y ? x < p.x : y < p.y;
    }
    int x, y;
};

int n;
int in[100 * 1000 + 1][2];

uint32 get_next(uint32 v) {
    uint32 w;
    uint32 t = v | (v - 1);
#ifdef WIN32
    unsigned long res;
    _BitScanForward(&res, v);
    w = (t + 1) | (((~t & -~t) - 1) >> (res + 1));
#else
    w = (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
#endif
    return w;
}

int simulation(multiset<Point> &for_x, multiset<Point, greater<Point> > &for_y,
        int left, int right, int top, int bottom) {
    int i;
    vector<Point> back;
    multiset<Point>::iterator xi;
    multiset<Point>::iterator yi;
    multiset<Point>::reverse_iterator xri;
    multiset<Point>::reverse_iterator yri;
    for (i = 0; i < left; i++) {
        xi = for_x.begin();
        int x = xi->x;
        int y = xi->y;
        for_x.erase(xi);
        for_y.erase(Point(x, y));
        back.push_back(Point(x,y));
    }
    for (i = 0; i < right; i++) {
        xri = for_x.rbegin();
        int x = xri->x;
        int y = xri->y;
        for_x.erase(--xri.base());
        for_y.erase(Point(x, y));
        back.push_back(Point(x,y));
    }
    for (i = 0; i < top; i++) {
        yri = for_y.rbegin();
        int x = yri->x;
        int y = yri->y;
        for_y.erase(--yri.base());
        for_x.erase(Point(x, y));
        back.push_back(Point(x,y));
    }
    for (i = 0; i < bottom; i++) {
        yi = for_y.begin();
        int x = yi->x;
        int y = yi->y;
        for_y.erase(yi);
        for_x.erase(Point(x, y));
        back.push_back(Point(x,y));
    }
    // calculate
    xi = for_x.begin();
    xri = for_x.rbegin();
    yi = for_y.begin();
    yri = for_y.rbegin();

    int result = max(xri->x - xi->x, yri->y - yi->y);

    // recover
    for (i = 0; i < back.size(); i++) {
        for_x.insert(back[i]);
        for_y.insert(back[i]);
    }

    return result;
}

void solve() {
    scanf("%d", &n);
    int i;
    multiset<Point> for_x;
    multiset<Point, greater<Point> > for_y;

    for (i = 0; i < n; i++) {
        scanf("%d %d", &in[i][X], &in[i][Y]);
        for_x.insert(Point(in[i][X], in[i][Y]));
        for_y.insert(Point(in[i][X], in[i][Y]));
    }

    // for all cases
    uint32 flag = 0x7; // 111 (2)
    int solution = 0x7FFFFFFF;
    while (flag <= 0xe00) { // 1110 0000 0000 (2)
        // 000      000     000     000   (2)
        // left     right   top     bottom
        int left = popcount(flag & 0xe00);      // 1110 0000 0000
        int right = popcount(flag & 0x1c0);     // 0001 1100 0000
        int top = popcount(flag & 0x38);        // 0000 0011 1000
        int bottom = popcount(flag & 0x7);      // 0000 0000 0111

        solution = min(solution, simulation(for_x, for_y, left, right, top, bottom));
        flag = get_next(flag);
    }
    trace("%d\n", solution);
}

int main(int, char*[]) {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {solve();}
    return 0;
}

