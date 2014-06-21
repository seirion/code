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

class PointX { public:
    PointX() : x(0), y(0) {}
    PointX(int x_, int y_) : x(x_), y(y_) {}
    ~PointX() {}
    bool operator <(const PointX& p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
    int x, y;
};

class PointY { public:
    PointY() : x(0), y(0) {}
    PointY(int x_, int y_) : x(x_), y(y_) {}
    ~PointY() {}
    bool operator <(const PointY& p) const {
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

int simulation(multiset<PointX> &for_x, multiset<PointY> &for_y, int left, int right, int top, int bottom) {
    int i;
    vector<PointX> back;
    multiset<PointX>::iterator xi;
    multiset<PointY>::iterator yi;
    multiset<PointX>::reverse_iterator xri;
    multiset<PointY>::reverse_iterator yri;
    for (i = 0; i < left; i++) {
        xi = for_x.begin();
        int x = xi->x;
        int y = xi->y;
        for_x.erase(xi);
        for_y.erase(PointY(x, y));
        back.push_back(PointX(x,y));
    }
    for (i = 0; i < right; i++) {
        xri = for_x.rbegin();
        int x = xri->x;
        int y = xri->y;
        for_x.erase(--xri.base());
        for_y.erase(PointY(x, y));
        back.push_back(PointX(x,y));
    }
    for (i = 0; i < top; i++) {
        yri = for_y.rbegin();
        int x = yri->x;
        int y = yri->y;
        for_y.erase(--yri.base());
        for_x.erase(PointX(x, y));
        back.push_back(PointX(x,y));
    }
    for (i = 0; i < bottom; i++) {
        yi = for_y.begin();
        int x = yi->x;
        int y = yi->y;
        for_y.erase(yi);
        for_x.erase(PointX(x, y));
        back.push_back(PointX(x,y));
    }
    // calculate
    xi = for_x.begin();
    xri = for_x.rbegin();
    yi = for_y.begin();
    yri = for_y.rbegin();

    int xxx = xri->x;
    int result = max(xri->x - xi->x, yri->y - yi->y);

    // recover
    for (i = 0; i < back.size(); i++) {
        for_x.insert(back[i]);
        for_y.insert(PointY(back[i].x, back[i].y));
    }

    return result;
}

void solve() {
    scanf("%d", &n);
    int i;
    multiset<PointX> for_x;
    multiset<PointY> for_y;

    for (i = 0; i < n; i++) {
        scanf("%d %d", &in[i][X], &in[i][Y]);
        for_x.insert(PointX(in[i][X], in[i][Y]));
        for_y.insert(PointY(in[i][X], in[i][Y]));
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

        //trace("%d %d %d %d      %d\n", left, right, top, bottom, left + right + top + bottom);
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

