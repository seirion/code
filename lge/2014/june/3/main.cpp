// http://lgecodejam.com
// lge code jam June, 2014
// problem.3
// hyungyu.jang@lge.com


#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
    #include <trace/trace.h>
    #include <intrin.h>
#else
    #define trace printf
#endif

#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <functional>
#include <algorithm>

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
    bool operator >(const Point& p) const {
        return x == p.x ? y > p.y : x > p.x;
    }
    int x, y;
};

typedef multiset<Point> MinSet;
typedef multiset<Point, greater<Point> > MaxSet;

int n;
MinSet min_xy, min_yx;
MaxSet max_xy, max_yx;

template<typename T>
void remove(T &s, const Point p) {
    typename T::iterator i = s.begin();
    for (; i != s.end(); i++) {
        if (i->x == p.x && i->y == p.y) {
            s.erase(i);
            return;
        }
    }
}

int simulation(int left, int right, int top, int bottom) {
    MinSet min_xy_(min_xy);
    MinSet min_yx_(min_yx);
    MaxSet max_xy_(max_xy);
    MaxSet max_yx_(max_yx);
    int i;
    for (i = 0; i < left; i++) {
        Point p = *min_xy_.begin();
        Point q(p.y, p.x);
        remove<MinSet>(min_yx_, q);
        remove<MaxSet>(max_yx_, q);
        min_xy_.erase(min_xy_.begin());
    }
    for (i = 0; i < right; i++) {
        Point p = *max_xy_.begin();
        Point q(p.y, p.x);
        remove<MinSet>(min_yx_, q);
        remove<MaxSet>(max_yx_, q);
        max_xy_.erase(max_xy_.begin());
    }
    for (i = 0; i < bottom; i++) {
        Point p = *min_yx_.begin();
        Point q(p.y, p.x);
        remove<MinSet>(min_xy_, q);
        remove<MaxSet>(max_xy_, q);
        min_yx_.erase(min_yx_.begin());
    }
    for (i = 0; i < top; i++) {
        Point p = *max_yx_.begin();
        Point q(p.y, p.x);
        remove<MinSet>(min_xy_, q);
        remove<MaxSet>(max_xy_, q);
        max_yx_.erase(max_yx_.begin());
    }

    return max(max_xy_.begin()->x - min_xy_.begin()->x, max_yx_.begin()->x - min_yx_.begin()->x);
}

void solve() {
    min_xy.clear();
    min_yx.clear();
    max_xy.clear();
    max_yx.clear();
    scanf("%d", &n);
    int i, x, y;
    for (i = 0; i < 4; i++) {
        scanf("%d %d", &x, &y);
        min_xy.insert(Point(x, y));
        max_xy.insert(Point(x, y));
        min_yx.insert(Point(y, x));
        max_yx.insert(Point(y, x));
    }

    for (; i < n; i++) {
        scanf("%d %d", &x, &y);
        min_xy.insert(Point(x, y));
        max_xy.insert(Point(x, y));
        min_yx.insert(Point(y, x));
        max_yx.insert(Point(y, x));
        min_xy.erase(--min_xy.rbegin().base());
        min_yx.erase(--min_yx.rbegin().base());
        max_xy.erase(--max_xy.rbegin().base());
        max_yx.erase(--max_yx.rbegin().base());
    }

    // for all cases
    int solution = 0x7FFFFFFF;
    int direct[4]; // left, right, top, bottom
    for (i = 0; i < 4; i++) {
        memset(direct, 0, sizeof(int) * 4);
        direct[i] = 3;
        solution = min(solution, simulation(direct[0], direct[1], direct[2], direct[3]));
        direct[0] = direct[1] = direct[2] = direct[3] = 1;
        direct[i] = 0;
        solution = min(solution, simulation(direct[0], direct[1], direct[2], direct[3]));
    }
    for (i = 0; i < 4; i++) {
        memset(direct, 0, sizeof(int) * 4);
        direct[i] = 2;
        for (int j = 0; j < 3; j++) {
            direct[(i+j+1)%4] = 1;
            solution = min(solution, simulation(direct[0], direct[1], direct[2], direct[3]));
            direct[(i+j+1)%4] = 0;
        }
    }

    trace("%d\n", solution);
}

int main(int, char*[]) {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {solve();}
    return 0;
}

