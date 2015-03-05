// http://algospot.com/judge/problem/read/
#include <cstdio>
#include <limits>

using namespace std;

int month;
double n, rate;

void input() {
    scanf("%lf %d %lf", &n, &month, &rate);
}

bool possible(double value) {
    double current = n;
    const double RATE = 1.0 + (rate / 1200);
    for (int i = 0; i < month; i++) {
        current = current * RATE;
        current -= value;
        if (current <= 0.0) return true;
    }
    return false;
}

void solve() {
    double low(0.0), high(n*(1.0+(rate/1200))), mid;

    int limit = 100;
    while (limit-- > 0) {
        mid = (high + low) / 2;
        if (possible(mid)) {
            high = mid;
        }
        else {
            low = mid;
        }
    }

    printf("%.10lf\n", high);
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
