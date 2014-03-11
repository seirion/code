#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#ifndef INT_MAX
#define INT_MAX 1000000
#endif
int _n; // num
const int MAX_SIZE = 15;
int _distance [MAX_SIZE][MAX_SIZE]; // _distance
int _t [MAX_SIZE][1<<MAX_SIZE]; // for memoization

int getIndex(int flag) {
    int i;
    for (i = 0; i < _n; i++) {
        if (flag & (1 << i)) break;
    }
    return i;
}

int tsp(int from, int toFlag, int size) {
    if (_t[from][toFlag] > 0) {
        return _t[from][toFlag];
    }
    if (size == 1) {
        int to = getIndex(toFlag);
        return _distance[from][to];
    }

    int m = INT_MAX;
    for (int i = 0; i < _n; i++) {
        if (!(toFlag & (1 << i))) continue;

        int v = _distance[from][i] + tsp(i, (toFlag & ~(1<<i)), size-1);
        m = min(m, v);
    }

    _t[from][toFlag] = m;
    return m;
}

int findMin() {
    int m = INT_MAX;
    int limit = (1<<_n) - 1;
    for (int i = 0; i < _n; i++) {
        int v = tsp(i, limit & ~(1<<i), _n-1) + _distance[i][i];
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

    for (int k = 0; k < MAX_SIZE; k++) {
        memset(_t[k], 0, sizeof(int)*(1<<MAX_SIZE));
    }
    cout << findMin() << endl;
}

int main() {
    int num, i;
    cin >> num;

    for (i = 0; i < num; i++) {
        solve();
    }

    return 0;
}
