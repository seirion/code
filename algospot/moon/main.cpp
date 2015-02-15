// http://algospot.com/judge/problem/read/MOON
// http://mathworld.wolfram.com/Circle-CircleIntersection.html
// http://mathworld.wolfram.com/CircularSegment.html
#include <cstdio>
#include <cmath>

using namespace std;

const double PI = acos(-1.0);

double area(int M, int S, int C) {
    double x = (-S*S + M*M + C*C) / 2.0 / C;
    double y = sqrt(abs(M*M - x*x));
    double theta = 2.0 * acos(x / M);

    double circle = PI * M * M;
    double arch = circle * theta / 2 / PI;
    double triangle  = x * y;

    return arch - triangle;
}

void solve() {
    int M, S, C;
    scanf("%d %d %d", &M, &S, &C);

    double circle = PI * M * M;
    double left = area(M, S, C);
    double right = area(S, M, C);

    printf("%0.3f\n", circle - left - right);
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) { solve();}
    return 0;
}
