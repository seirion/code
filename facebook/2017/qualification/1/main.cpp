// https://www.facebook.com/hackercup/problem/1254819954559001/
// Facebook Hacker Cup 2017 Qualification Round
// Progress Pie
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

const char *B = "black";
const char *W = "white";

int p, x, y;

bool inCircle() {
    return x*x + y*y <= 50 * 50;
}

double cross(double x1, double y1, double x2, double y2) {
    return x1*y2 - x2*y1;
}

// | cos    -sin | |x|
// | sin     cos | |y|
//
// => | x cos  -  y sin |
//    | x sin  +  y cos |
bool leftOfEnd() {
    double theta = (360.0 * p / 100) * M_PI / 180;
    double x1 = /* 0 * cos(-theta) */ - 50 * sin(-theta);
    double y1 = /* 0 * sin(-theta) */ + 50 * cos(-theta);
    return cross(x, y, x1, y1) <= 0.0;
}

bool isBlack() {
    return inCircle() && leftOfEnd();
}

void solve(int k) {
    cin >> p >> x >> y;
    x -= 50; y -= 50; // make center (0, 0)
    printf("Case #%d: %s\n", k, isBlack() ? B : W);
}

int main() {
    int c; cin >> c;
    for (int i = 1; i <= c; i++) {
        solve(i);
    }
    return 0;
}
