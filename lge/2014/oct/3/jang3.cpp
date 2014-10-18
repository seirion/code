// hyungyu.jang@lge.com
// problem 3

#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Point { public:
    Point (int x_, int y_, int i_ = 0, int d_ = 0) : x(x_), y(y_), i(i_), d(d_) {}
    ~Point() {}
    int x, y, i, d; // i : index, d : direction
    bool operator > (const Point &p) const {
        if (x == p.x) return y < p.y;
        return x > p.x;
    }
};

enum {UP = 1, DOWN, LEFT, RIGHT,};

int M, N, K;
int xy[5000][2];
int direct[5000];
set<Point> s;

void input() {
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &xy[i][0], &xy[i][1], &direct[i]);
    }
}

int find(int k) { // find k-th point from right
    vector<Point> v; // index
    for (int i = 0; i < N; i++) {
        if (direct[i] == RIGHT) {
            v.push_back(Point(xy[i][0], xy[i][1], i, direct[i]));
        }
    }
    
    if (v.size() <= k) return -1;
    sort(v.begin(), v.end(), greater<Point>());

    for (; k > 0; k--) {
        if (v[k].x != v[k-1].x) break;
    }
    return v[k].i;
}

const int MT /*MATCHING_TABEL*/ [5][5] = { // +, -, 0, direction
    {0, 0, 0, 0, 0}, // skip 0-th
    {LEFT, RIGHT, DOWN, 0, 1}, // 1(UP)
    {RIGHT, LEFT, UP, 0, 1},   // 2(DOWN)
    {UP, DOWN, RIGHT, 1, 0},   // 3(LEFT)
    {DOWN, UP, LEFT, 1, 0}     // 4(RIGHT)
};

int get_last(int index, int limit, int &last_distance) {
    int last_index = -1;
    last_distance = 0;
    int d = direct[index];
    for (int i = 0; i < N; i++) { // full-search
        if (index == i) continue;
        if (d == RIGHT && xy[i][0] <= xy[index][0]) continue; // un-matching
        if (d == LEFT && xy[i][0] >= xy[index][0]) continue; // un-matching
        if (d == UP && xy[i][1] <= xy[index][1]) continue; // un-matching
        if (d == DOWN && xy[i][1] >= xy[index][1]) continue; // un-matching
        // +
        if (direct[i] == MT[d][0] && xy[i][0] - xy[index][0] == xy[i][1] - xy[index][1]) {
            int temp = abs(xy[i][0] - xy[index][0]) * 2;
            if (temp > last_distance && temp < limit) {
                last_distance = temp;
                last_index = i;
            }
        }
        else if (direct[i] == MT[d][1] && xy[i][0] - xy[index][0] == -(xy[i][1] - xy[index][1])) {
            int temp = abs(xy[i][0] - xy[index][0]) * 2;
            if (temp > last_distance && temp < limit) {
                last_distance = temp;
                last_index = i;
            }
        }
        else if (direct[i] == MT[d][2] && xy[i][MT[d][3]] == xy[index][MT[d][3]]) {
            int temp = abs(xy[i][MT[d][4]] - xy[index][MT[d][4]]);
            if (temp > last_distance && temp < limit) {
                last_distance = temp;
                last_index = i;
            }
        }
    }

    return last_index;
}

int find_one(int index, int limit) {
    if (limit < 2) { return index; }
    int distance;
    int last = get_last(index, limit, distance);
    if (last == -1) return index;
    return find_one(last, distance);
}

void solve () {
    int k_th = find(K-1);

    if (k_th == -1) {
        printf("0 0\n");
        return;
    }

    int one = find_one(k_th, (M - xy[k_th][0]) * 2);
    int time = M - xy[k_th][0];
    printf("%d %d\n", time, one+1);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) { input(); solve(); }
    return 0;
}
