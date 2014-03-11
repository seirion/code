//#include <iostream>
#include <cstdio>
#include <cstring>

#ifndef min
#define min(a, b) (a) > (b) ? (b) : (a)
#endif

using namespace std;

int _n;
const int SIZE = 20;
double _w [SIZE][SIZE];
double _t [SIZE][1<<SIZE];


double calValue(int from, int flag) {
    double m = 300000.0;
    int i = 1, j = 0;
    for (; i < flag; i <<= 1, j++) {
        if (flag & i) {
            m = min(m, (_w[from][j] + _t[j][flag & ~i]));
        }
    }

    return m;
}

void tsp() {
    int limit = (1<<_n) - 1;

    for (int flag = 3; flag < limit; flag++) {
        for (int i = 0; i < _n; i++) {
            if (flag & (1 << i)) continue;
            _t[i][flag] = calValue(i, flag);
        }
    }

    //
    double m = 300000.0;
    for (int i = 0; i < _n; i++) {
        m = min(m, _t[i][limit & ~(1<<i)]);
    }

    printf("%.10lf\n", m);
}


void solve() {
    int i,j;
    //cin >> _n;
    scanf("%d\n", &_n);
    memset(_t, 0, sizeof(double)*SIZE*(1<<SIZE));
    for (i = 0; i < _n; i++) {
        for (j = 0; j < _n-1; j++) {
            //cin >> _w[i][j];
            scanf("%lf ", &_w[i][j]);
            _t[i][1<<j] = _w[i][j];
        }
            scanf("%lf\n", &_w[i][j]);
            _t[i][1<<j] = _w[i][j];
    }

    tsp();
}

int main() {
    int num;
    //cin >> num;
    scanf("%d\n", &num);
    for (int i = 0; i < num; i++) solve();

    return 0;
}
