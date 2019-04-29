#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;
const int SIZE = 1002;
int P, Q;
map<int, int> X, Y;
int inx[SIZE], iny[SIZE];
char ind[SIZE];

int m[SIZE][SIZE];

void input() {
    X.clear();
    Y.clear();
    memset(m, 0, sizeof(int) * SIZE * SIZE);
    cin >> P >> Q;
    for (int i = 0; i < P; i++) {
        int x, y;
        char d;
        cin >> x >> y >> d;
        inx[i] = x;
        iny[i] = y;
        ind[i] = d;
        X[x] = 0;
        Y[y] = 0;

        if (d == 'W') { // <-
            X[x-1] = 0;
        } else if (d == 'E') { // ->
            X[x+1] = 0;
        } else if (d == 'S') { // up
            Y[y-1] = 0;
        } else { // down
            Y[y+1] = 0;
        }
    }
    X[0] = 0;
    Y[0] = 0;

    int i = 0;
    for (auto &x: X) {
        x.second = i++;
    }
    i = 0;
    for (auto &y: Y) {
        y.second = i++;
    }
}

int findv(int index, map<int, int>& c) {
    for (auto it: c) {
        if (it.second == index)  return it.first;
    }
    return 0;
}

void solve() {
    const int SIZEX = X.size();
    const int SIZEY = Y.size();

    for (int i = 0; i < P; i++) {
        int &x = X[inx[i]];
        int &y = Y[iny[i]];
        char &d = ind[i];

        int left, right, up, down;

        if (d == 'W') { // <-
            left = 0;
            right = x;
            up = 0;
            down = SIZEY;
        } else if (d == 'E') { // ->
            left = x + 1;
            right = SIZEX;
            up = 0;
            down = SIZEY;
        } else if (d == 'S') { // up
            left = 0;
            right = SIZEX;
            up = 0;
            down = y;
        } else { // down
            left = 0;
            right = SIZEX;
            up = y+1;
            down = SIZEY;
        }

        for (int x = left; x < right; x++) {
            for (int y = up; y < down; y++) {
                m[x][y]++;
            }
        }
    }


    int best = 0;
    int bestx, besty;
    for (int x = 0; x < SIZEX; x++) {
        for (int y = 0; y < SIZEY; y++) {
            if (best < m[x][y])  {
                best = m[x][y];
                bestx = x;
                besty = y;
            }
        }
    }

    int cx = findv(bestx, X);
    int cy = findv(besty, Y);

    cout << cx << " " << cy << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        input();
        solve();
    }
    return 0;
}
