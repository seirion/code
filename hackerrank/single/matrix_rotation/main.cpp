// https://www.hackerrank.com/challenges/matrix-rotation-algo
// [Algo] Matrix Rotation
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
typedef pair<int, int> Point;

int row, col, m;
int in[300*300];
int out[300*300];

int minr, minc, maxr, maxc;

vector<int> get_points() {
    vector<int> v;

    int now = minr*col + minc;
    int limit = maxc - minc;
    while (limit--) {
        v.push_back(now);
        now += 1;
    }

    now = v.back();
    limit = maxr - minr - 1;
    while (limit--) {
        now += col;
        v.push_back(now);
    }

    now = v.back();
    limit = maxc - minc - 1;
    while (limit--) {
        now -= 1;
        v.push_back(now);
    }

    now = v.back();
    limit = maxr - minr - 2;
    while (limit--) {
        now -= col;
        v.push_back(now);
    }

    return v;
}

int main() {
    cin >> row >> col >> m;
    int limit = row * col;
    for (int i = 0; i < limit; i++) cin >> in[i];

    minr = minc = 0;
    maxr = row; maxc = col;

    while (minr < maxr && minc < maxc) {
        vector<int> points = get_points();

        int size = points.size();
        for (int i = 0; i < size; i++) {
            int &oo = points[i];
            int &ii = points[(i+m)%size];
            out[oo] = in[ii];
        }

        minr++; minc++;
        maxr--; maxc--;
    }

    for (int i = 0; i < limit; i++) {
        cout << out[i] << " ";
        if ((i+1)%col == 0) cout << endl;
    }
    return 0;
}
