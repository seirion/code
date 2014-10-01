// hyungyu.jang@lge.com
// problem 3

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Point { public:
    Point (int x_, int y_) : x(x_), y(y_) {}
    ~Point() {}
    int x, y;
    bool operator < (const Point &p) const {
        if (x == y) return y < p.y;
        return x < p.x;
    }
};

enum {UP = 1, DOWN, LEFT, RIGHT,};

int M, N, K;
int xy[5000][2];
int direct[5000];
map<Point, int> s;

void input() {
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &xy[i][0], &xy[i][1], &direct[i]);
    }
}

bool sort_by_x(int a, int b) {
    return xy[a][0] < xy[b][0];
}

int find(int k) {
    vector<int> v; // index
    for (int i = 0; i < N; i++) {
        if (direct[i] == RIGHT) {
            v.push_back(i);
        }
    }
    
    if (v.size() <= k) return -1;
    sort(v.begin(), v.end(), sort_by_x);
    return v[k];
}

int find_rec(int index, int d) {
}

void solve () {
    int kk = find(K-1);

    if (kk == -1) {
        printf("0 0\n");
        return 0;
    }

    int rr = find_rec(kk, UP);
    int time = M - xy[kk][x];
    printf("%d %d\n", xy[kk]);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) { input(); solve(); }
    return 0;
}
