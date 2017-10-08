// http://algospot.com/judge/problem/read/
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
bool visit[102][102] = {false, };

class T {public: 
    int n, i;
    bool operator <(const T &t) const { return n > t.n; } // greater
    T(int n_, int i_) : n(n_), i(i_) {}
};

int row, col;
int in[102][102];

void input() {
    scanf("%d %d\n", &col, &row);

    for (int r = 0; r < row; r++) {
        string buffer; cin >> buffer;
        for (int c = 0; c < col; c++) {
            in[r][c] = buffer[c] - '0';
        }
    }
}

void solve() {
    priority_queue<T> q;
    q.push(T(0, 0));
    visit[0][0] = true;

    while (!q.empty()) {
        T x = q.top(); q.pop();
        int r = x.i / col;
        int c = x.i % col;
        if (r+1 == row && c+1 == col) {
            cout << x.n << endl;
            return;
        }

        if (r > 0 && !visit[r-1][c]) { // up
            visit[r-1][c] = true;
            q.push(T(x.n + in[r-1][c], (r-1) * col + c));
        }
        if (r+1 < row && !visit[r+1][c]) { // down
            visit[r+1][c] = true;
            q.push(T(x.n + in[r+1][c], (r+1) * col + c));
        }
        if (c+1 < col && !visit[r][c+1]) { // right
            visit[r][c+1] = true;
            q.push(T(x.n + in[r][c+1], r * col + c + 1));
        }
        if (c > 0 && !visit[r][c-1]) { // left
            visit[r][c-1] = true;
            q.push(T(x.n + in[r][c-1], r * col + c - 1));
        }
    }
    cout << 0 << endl; // cannot reach here
}

int main() {
    input();
    solve();
    return 0;
}
