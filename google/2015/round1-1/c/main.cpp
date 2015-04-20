// https://code.google.com/codejam/contest/4224486/dashboard#s=p2
// Problem C. Logging

#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const double PI = atan(1.0) * 4;

class XY { public:
    XY(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
    XY operator -(const XY &a) { return XY(x-a.x, y-a.y); }
    double angle() { return atan2(y, x); }
    bool operator <(const XY &a) const {
        return (x == a.x) ? (y < a.y) : (x < a.x);
    }
    int x, y;
};

int n;
XY xy[3000];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> xy[i].x >> xy[i].y;
    }
}

int solve() {
    vector<double> angle;
    for (int i = 0; i < n; i++) {
        angle.clear();
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            angle.push_back((xy[i] - xy[j]).angle() * 180.0 / PI);
        }

        sort(angle.begin(), angle.end());
        int size = angle.size();
        for (int j = 0; j < size; j++) {
            angle.push_back(angle[j] + 360.0);
        }

        int maxi(0), k(0);
        for (int j = size; j < angle.size(); j++) {
            while (angle[k]+180.0 < angle[j]) k++;
            maxi = max(maxi, j-k+1);
        }
        printf("%d\n", size-maxi);
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        input();
        printf("Case #%d:\n", i);
        solve();
    }
}

