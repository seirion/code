// https://www.hackerrank.com/contests/w17/challenges/count-fridays-the-13-th
// Count Fridays the 13-th
#include <iostream>
#include <cstdio>

using namespace std;
// getting day of week, given date (yyyy.mm.dd)
// 0 is Sunday, 1 is Monday ...
int day_from_date(int y, int m, int d) {
    int c;
    if (m < 3) {
        y--;
        m += 10;
    }
    else {
        m -= 2;
    }
    c = y / 100;
    y = y % 100;

    int x = (d + (26*m-2)/10 - 2*c + y + y/4 + c/4) % 7;
    if (x < 0) x += 7;
    return x;
}

void solve() {
    int y1, m1, d1, y2, m2, d2;
    scanf("%0d %02d %d %02d %02d %d", &d1, &m1, &y1, &d2, &m2, &y2);

    if (d1 > 13) {
        m1++;
        if (m1 == 13) {
            m1 = 1; y1++;
        }
    }

    if (d2 >= 13) {
        m2++;
        if (m2 == 13) {
            m2 = 1; y2++;
        }
    }

    // check
    int c(0);
    while (y1 != y2 || m1 != m2) {
        if (day_from_date(y1, m1, 13) == 5 /*FRI*/) c++;
        m1++;
        if (m1 == 13) {
            m1 = 1; y1++;
        }
    }

    cout << c << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

