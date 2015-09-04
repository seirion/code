// http://algospot.com/judge/problem/read/BOARDCOVER
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

class Tile { public:
    Tile(int r_ = 0, int c_ = 0) : r(r_), c(c_) {}
    int r, c;
    bool operator < (const Tile &t) const {
        return (r == t.r ? c < t.c : r < t.r);
    }
};

const int CAND [4][3][2] = {
    {{0, 0}, {0, 1} ,{1, 1}},
    {{0, 0}, {1, 0} ,{0, 1}},
    {{0, 0}, {1, 0} ,{1, 1}},
    {{0, 0}, {1, 0} ,{1, -1}}
};

int h, w;
char in[20][22];
set<Tile> remain;

void input() {
    cin >> h >> w;
    cin.get();

    remain.clear();
    for (int i = 0; i < h; i++) {
        fgets(in[i], 22, stdin);
        for (int j = 0; j < w; j++) {
            if (in[i][j] == '.') remain.insert(Tile(i, j));
        }
    }
}

bool canbe(int index, int row, int col) {
    for (int i = 0; i < 3; i++) {
        int r = row + CAND[index][i][0];
        int c = col + CAND[index][i][1];
        if (remain.find(Tile(r, c)) == remain.end()) return false;
    }
    return true;
}

void cover(int index, int row, int col) {
    for (int i = 0; i < 3; i++) {
        int r = row + CAND[index][i][0];
        int c = col + CAND[index][i][1];
        remain.erase(Tile(r, c));
    }
}

void recover(int index, int row, int col) {
    for (int i = 0; i < 3; i++) {
        int r = row + CAND[index][i][0];
        int c = col + CAND[index][i][1];
        remain.insert(Tile(r, c));
    }
}

int get_possible() {
    if (remain.size() == 0) {
        return 1;
    }

    int count = 0;
    Tile c = *remain.begin();
    for (int i = 0; i < 4; i++) {
        if (canbe(i, c.r, c.c)) {
            cover(i, c.r, c.c);
            count += get_possible();
            recover(i, c.r, c.c);
        }
    }
    return count;
}

void solve() {
    cout << (remain.size() % 3 == 0 ? get_possible() : 0) << endl;
}

int main(int argc, char *argv[]) {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
