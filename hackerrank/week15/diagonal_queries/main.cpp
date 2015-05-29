// https://www.hackerrank.com/contests/w15/challenges/diagonal-queries
// Weekly Challenges - Week 15 Diagonal Queries 
#include <iostream>

using namespace std;

typedef long long int64;

const int64 MOD = 1000000007LL;
int64 row, col;
int64 sum[200002] = {0, };

void (*fn[26])(int64, int64);

void Qc(int64 c, int64 v) { 
    int64 s(v), index(row+c-1);
    for (int64 i = 0; i < row; i++, index--) {
        sum[index] += s;
        s += v;
    }
}
void Qr(int64 r, int64 v) {
    int64 s(v), index(row-r+1);
    for (int64 i = 0; i < col; i++, index++) {
        sum[index] += s;
        s += v;
    }
}
void Qd(int64 from, int64 to) {
    int64 v(0);
    for (int64 i = from; i <= to; i++) {
        v += sum[i];
    }
    cout << (v%MOD) << "\n";
}
void Qs(int64 r1, int64 c1, int64 r2, int64 c2, int64 v) {
    int64 from = row+1-r2    +    c1-1; // (r2, c1)
    int64 to = row+1-r1      +    c2-1; // (r1, c2);

    int64 i(0), s(0), h(r2-r1+1), w(c2-c1+1); // height, width

    if (w >= h) {
        for (; i < h; i++) {
            s += v;
            sum[from+i] += s;
        }
        i += from;
        for (; i <= to; i++) {
            sum[i] += s;
        }
        s -= v;
        for (i = 0; i < h; i++) {
            sum[to-i] -= s;
            s -= v;
        }
    }
    else {
        for (; i < w; i++) {
            s += v;
            sum[from+i] += s;
        }
        i += from;
        for (; i <= to; i++) {
            sum[i] += s;
        }
        s -= v;
        for (i = 0; i < w; i++) {
            sum[to-i] -= s;
            s -= v;
        }
    }
}

int main() {
    fn['c'-'a'] = Qc;
    fn['r'-'a'] = Qr;
    fn['d'-'a'] = Qd;

    int64 query;
    cin >> row >> col >> query;
    for (int64 i = 0; i < query; i++) {
        string s; int64 v[5];
        cin >> s;
        switch (s[1]) {
            case 's':
                cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];
                Qs(v[0], v[1], v[2], v[3], v[4]);
                break;
            default:
                cin >> v[0] >> v[1];
                fn[s[1]-'a'](v[0], v[1]);
                break;
        }
    }
    return 0;
}
