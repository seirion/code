// https://www.hackerrank.com/contests/w23/challenges/treasure-hunting
// Treasure Hunting
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

double x, y, a, b;
int main() {
    cin >> x >> y >> a >> b; // y = b/a x

    // y = - a / b x + c (x1, y1)
    // xx, yy 는 직선 위의 점이며 (x, y) 와 최단거리
    double xx = (a * b) / (a*a + b*b) * (y + a / b * x);
    double yy = b / a * xx;

    double dx = (x - xx);
    double dy = (y - yy);
    bool right = (a * y - b * x) < 0;

    printf("%0.4f\n%0.4f\n",
            sqrt(xx*xx + yy*yy) / sqrt(a*a + b*b),
            sqrt(dx*dx + dy*dy) / sqrt(a*a + b*b) * (right ? -1 : 1));
    return 0;
}
