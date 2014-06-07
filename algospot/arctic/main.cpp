// http://algospot.com/judge/problem/read/ARCTIC
#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

class Pos {public:
    Pos() {}
    Pos(double x_, double y_) : x(x_), y(y_) {}
    ~Pos() {}
    bool operator<(const Pos& p) const {return true;}
    double x, y;
};

int n;
vector<Pos> in;
double distance_square[101][101];

void getInput() {
    double x, y;
    cin >> n;
    int i;
    in.clear();
    for (i = 0; i < n; i++) {
        cin >> x >> y;
        in.push_back(Pos(x, y));
    }

    for (i = 0; i < n; i++) {
        Pos &a = in[i];
        for (int j = 0; j < n; j++) {
            Pos &b = in[j];
            distance_square[i][j] = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
        }
    }
}

bool canbe(double m) {
    m = m * m; // square
    deque<int> q;
    q.push_back(0);
    size_t s = in.size();
    vector<bool> visit(s, false);
    visit[0] = true;

    int count = 0;
    while (!q.empty()) {
        int index = q.front();
        q.pop_front();
        count++;

        for (int i = 1; i < s; i++) {
            if (!visit[i] && distance_square[index][i] <= m) {
                visit[i] = true;
                q.push_back(i);
            }
        }
    }

    return count == s;
}

void solve() {
    double from(0.0), to(1001.0), mid;
    for (int i = 0; i < 100; i++) {
        mid = (from + to) / 2;
        if (canbe(mid)) {
            to = mid;
        }
        else {
            from = mid;
        }
    }

    printf("%.02f\n", mid);
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        getInput(); solve();
    }
    return 0;
}
