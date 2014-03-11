#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int _n; // input num
const int SIZE_ = 20;
double _distance [SIZE_][SIZE_]; // distance
double _memory [SIZE_][1<<SIZE_]; // for memoization

int getIndex(int flag) {
    int i;
    for (i = 0; i < _n; i++) {
        if (flag & (1 << i)) break;
    }
    return i;
}

double tsp(int from, int toFlag, int size) {
    if (_memory[from][toFlag] > 0) {
        return _memory[from][toFlag];
    }
    if (size == 1) {
        int to = getIndex(toFlag);
        return _distance[from][to];
    }

    double m = 1500000.0;
    for (int i = 0; i < _n; i++) {
        if (!(toFlag & (1 << i))) continue;

        double v = _distance[from][i] + tsp(i, (toFlag & ~(1<<i)), size-1);
        m = min(m, v);
    }

    _memory[from][toFlag] = m;
    return m;
}

double findMin() {
    double m = 150000.0;
    for (int i = 0; i < _n; i++) {
        double v = tsp(i, ~(1<<i), _n-1) + _distance[i][i];
        m = min(m, v);
    }

    return m;
}


void solve() {
    cin >> _n;

    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _n; j++) {
            cin >> _distance[i][j];
        }
    }

    memset(_memory, 0, sizeof(double)*SIZE_*(1<<SIZE_));
    double minValue = findMin();
    printf("%.10lf\n", minValue);
}

int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        solve();
    }

    return 0;
}
