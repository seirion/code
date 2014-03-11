#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define INT_MAX 1000000

int _n;
const int SIZE = 20;
int _distance [SIZE][SIZE];
int _memory [SIZE][1<<SIZE];


void getMin(int from, int toFlag) {
    int remain = toFlag;
    int i, ii;
    int m = INT_MAX;

    while (remain) {
        i = __builtin_ctz(remain);
        ii = remain & -remain;
        m = min(m, (_distance[from][i] + _memory[i][toFlag & ~ii]));
        remain &= remain - 1;
    }
    _memory[from][toFlag] = m;
}

int getMin() {
    int limit = (1<<_n) - 1;
    int i, remain;
    for (int flag = 3; flag < limit; flag++) {
        remain = limit & ~flag;
        while (remain) {
            i = __builtin_ctz(remain);
            remain &= remain - 1;
            if (_memory[i][flag] > 0) continue;
            getMin(i, flag);
        }
    }

    int m = INT_MAX;
    for (int i = 0; i < _n; i++) {
        m = min(m, _memory[i][limit & ~(1<<i)]);
    }

    return m;
}


void solve() {
    cin >> _n;
    memset(_memory, 0, sizeof(int)*SIZE*(1<<SIZE));
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _n; j++) {
            cin >> _distance[i][j];
            _memory[i][1<<j] = _distance[i][j];
        }
    }

    cout << getMin() << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) solve();

    return 0;
}
