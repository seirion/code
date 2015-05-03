// http://codeforces.com/contest/540/problem/C
// C. Ice Cave
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
 
class Point { public:
    Point(int r_ = 0, int c_ = 0) : r(r_), c(c_) {}
    bool operator <(const Point &p) const {
        return (r == p.r) ? c < p.c: r < p.r;
    }
    bool operator==(const Point &p) const {
        return (r == p.r && c == p.c);
    }
    int r, c;
};

int row, col;
char in [502][502];

int main() {
    scanf("%d %d\n", &row, &col);
    for (int r = 0; r < row; r++) {
        fgets(in[r], 502, stdin);
    }

    Point from, to;
    scanf("%d %d", &from.r, &from.c);
    scanf("%d %d", &to.r, &to.c);

    from.r--; from.c--;
    to.r--; to.c--;

    queue<Point> Q;
    Q.push(Point(from.r, from.c));
    in[from.r][from.c] = 'X';
    while (!Q.empty()) {
        Point now = Q.front();
        Q.pop();

        vector<Point> cand;
        if (now.r > 0) cand.push_back(Point(now.r-1, now.c));
        if (now.r+1 < row) cand.push_back(Point(now.r+1, now.c));
        if (now.c > 0) cand.push_back(Point(now.r, now.c-1));
        if (now.c+1 < col) cand.push_back(Point(now.r, now.c+1));


        for (auto &next : cand) {
            int r = next.r;
            int c = next.c;
            if (in[r][c] == '.') {
                in[r][c] = 'X';
                Q.push(Point(r, c));
            }
            else if (next == to) {
                cout << "YES" << endl; return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}
