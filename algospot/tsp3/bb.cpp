//http://raisonde.tistory.com/entry/Branch-and-bound-%EA%B8%B0%EB%B2%95%EC%9D%84-%EC%9D%B4%EC%9A%A9%ED%95%9C-TSP
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cfloat> // DBL_MAX
#include <vector>
#include <algorithm>

#ifndef min
#define min(a, b) (a) > (b) ? (b) : (a)
#endif

using namespace std;

int _n;
double _s; // solution
const int SIZE = 20;
double _w [SIZE+1][SIZE];

class ibset { // index - bound set
public :
    ibset(int i, double b) : _i(i), _b(b) {}
    ~ibset() {}
    int _i; double _b;
    bool operator< (const ibset &o) const {return (_b < o._b);}
    bool operator> (const ibset &o) const {return (_b > o._b);}
    bool operator==(const ibset &o) const {return (_b == o._b);}
};

double getBound(int from, int flag) {
    double sum = 0.0;
    int i = 1, k = 0;
    for (; i < flag; i <<= 1, k++) {
        if (!(flag & i)) continue;
        double m = DBL_MAX;
        for (int j = 0; j < _n; j++) {
            if (from != j && (flag & (1<<j))) m = min(m, _w[k][j]);
        }
        sum += m;
    }
    return sum;
}

int getIndex(int flag) {
    for (int i = 0; i < _n; i++) {
        if (flag & (1<<i)) return i;
    }
    return -1;
}

void tsp(int from, double base, int size, int flag) {
    static int p = 0;
    if (p++ == 10) exit(0);
    if (size == 1) {
        int index = getIndex(flag);
    }
    cout << "from : " << from << "  base : " << base << "  size : " << size << "  flag: " << flag << endl;

    // getting bound
    vector<ibset> ib;
    for (int i = 0; i < _n; i++) {
        if (flag & (1<<i)) {
            double bound = base + getBound(i, flag);
            ib.push_back(ibset(i, bound));
        }
    }
    sort(ib.begin(), ib.end());

    for (int i = 0; i < (int)ib.size(); i++) {
        if (_s > ib[i]._b) {
            int index = ib[i]._i;
            cout << index << " " << ib[i]._b << endl;
            tsp(index, base + _w[from][index], size-1, flag & ~(1 << index));
        }
        else break;
    }
}

void solve() {
    int i,j;
    cin >> _n;
    //memset(_t, 0, sizeof(double)*SIZE*(1<<SIZE));
    for (i = 0; i < _n; i++) {
        for (j = 0; j < _n; j++) {
            cin >> _w[i][j];
            if (i == j) _w[i][j] = DBL_MAX;
            //_t[i][1<<j] = _w[i][j];
        }
    }
    for (; i < _n; i++) { // for starting from root base
        _w[_n][i] = 0.0;
    }

    _s = DBL_MAX; // initializing
    int flag = (1<<_n) - 1; // default flag (all node belong to the flag)
    tsp(_n, 0.0, _n, flag);
    printf("%0.10lf\n", _s);
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) solve();

    return 0;
}
