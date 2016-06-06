// http://codeforces.com/contest/677/problem/D
// D. Vanya and Treasure
#include <iostream>
#include <map>
#include <cstdlib>

#define x first
#define y second

using namespace std;

typedef pair<int, int> Point;
int row, col, k;
int in[300][300];

map<Point, int> m[90001];

void input() {
    cin >> row >> col >> k; 
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cin >> in[r][c];
            m[in[r][c]][make_pair(r, c)] = 0x7FFFFFFF;
        }
    }
}

void solve() {
    m[0][make_pair(0, 0)] = 0;
    for (int i = 1; i <= k; i++) {
        for (auto &it1: m[i-1]) {
            const Point &from = it1.first;
            for (auto &it2 : m[i]) {
                const Point &to = it2.first;
                int &dist = it2.second;
                dist = min(dist, it1.second + abs(from.x - to.x) + abs(from.y - to.y));
            }
        }
    }

    int r = 0x7FFFFFFF;
    for (auto it : m[k]) {
        r = min(r, it.second);
    }
    cout << r << endl;
}

int main() {
    input();
    solve();
    return 0;
}
