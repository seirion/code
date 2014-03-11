#include <iostream>
#include <cstring>

using namespace std;

int _n;
const int SIZE = 20;
int _w [SIZE][SIZE];
int _t [SIZE][1<<SIZE];


int calValue(int from, int flag) {
    int m = 300000;
    for (int i = 0; i < _n; i++) {
        if (i != from && flag & (1<<i)) {
            m = min(m, (_w[from][i] + _t[i][flag & ~(1<<i)]));
        }
    }
    return m;
}

int getMin() {
    int limit = (1<<_n) - 1;

    for (int flag = 3; flag < limit; flag++) {
        for (int i = 0; i < _n; i++) { // i -> flag
            if (flag & (1 << i) || _t[i][flag] > 0) continue;
            _t[i][flag] = calValue(i, flag);
        }
    }

    int m = 300000;
    for (int i = 0; i < _n; i++) {
        m = min(m, _t[i][limit & ~(1<<i)]);
    }
    return m;
}


void solve() {
    cin >> _n;
    memset(_t, 0, sizeof(int)*SIZE*(1<<SIZE));
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _n; j++) {
            cin >> _w[i][j];
            _t[i][1<<j] = _w[i][j];
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
