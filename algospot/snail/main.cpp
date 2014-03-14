// http://algospot.com/judge/problem/read/SNAIL
#include <iostream>
#include <cstdio>

using namespace std;

typedef unsigned int uint32;

int d; // depth
int day;
int n;
double _75[1001];
double _25[1001];
double com[1001][1002] = {0, }; // combination

void combination() {
    int i, j;
    for (i = 1; i < 1001; i++) {
        com[i][0] = (double)1;
        com[i][1] = (double)i;
    }

    for (i = 1; i < 1001; i++) {
        for (j = 2; j <= i + 1; j++) {
            com[i][j] = com[i-1][j-1] + com[i-1][j];
        }
    }
    _75[0] = 1.0;
    _25[0] = 1.0;
    _75[1] = .75;
    _25[1] = .25;
    for (int i = 2; i < 1001; i++) {
        _75[i] = _75[i-1] * .75;
        _25[i] = _25[i-1] * .25;
    }
}

void getInput() {
    cin >> d >> day;
}

void solve() {
    if (d > 2 * day) {
        cout << 0.0 << endl;
        return;
    }
    if (d <= day) {
        cout << 100.0 << endl;
        return;
    }

    d -= day;
    double p = .0;
    for (int i = d; i <= day; i++) { // combination
        p += _75[i] * _25[day - i] * com[day][i];
    }

    printf("%0.10f\n", p);
}

int main() {
    combination();
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
