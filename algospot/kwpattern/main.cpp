// http://algospot.com/judge/problem/read/KWPATTERN
#include <iostream>
#include <cstdio>

using namespace std;

const int YY [] = { // YYYY <-> mm:ss
    0,   1,  2,  3,  4,  5,
    10, 11, 12, 13, 14, 15,
    20, 21, 22, 23, 24, 25,
    30, 31, 32, 33, 34, 35,
    40, 41, 42, 43, 44, 45,
    50, 51, 52, 53, 54, 55,
    60, 61, 62, 63, 64, 65,
    70, 71, 72, 73, 74, 75,
    80, 81, 82, 83, 84, 85,
    90, 91, 92, 93, 94, 95
};
const int MM [] = { // MM <-> hh
    1, 2, 10, 11, 12
};
const int DD [] = { 11, 22 };

class Date {public:
    Date() {y1 = 12; y2 = 0; mm = 0; dd = 0;} // 2000-01-11 10:00:02
    int y1, y2, mm, dd;

    Date& operator++(int) {
        if (++dd < 2) return *this;
        dd = 0;
        if (++mm < 5) return *this;
        mm = 0;
        if (++y2 < 60) return *this;
        y2 = 0;
        y1++;
        return *this;
    }
    void print() {
        int year = YY[y1] * 100 + YY[y2];
        int month = MM[mm];
        int day = DD[dd];

        int hour = (month % 10) * 10 + month / 10;
        int min = (YY[y2] % 10) * 10 + YY[y2] / 10;
        int sec = (YY[y1] % 10) * 10 + YY[y1] / 10;
        printf("%d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, min, sec);
    }
};

int n;
Date solution[10002];

void make() {
    Date date;
    for (int i = 1; i <= 10000; i++) {
        solution[i] = date;
        date++;
    }
}

int main() {
    make();
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int index;
        cin >> index;
        solution[index].print();
    }
    return 0;
}
