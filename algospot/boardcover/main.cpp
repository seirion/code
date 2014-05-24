// http://algospot.com/judge/problem/read/BOARDCOVER
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

class Tile { public:
    Tile() {}
    Tile(int x, int y) : h(x), w(y) {}
    int h, w;
    bool operator < (const Tile &t) const {
        return (h == t.h ? w < t.w : h < t.h);
    }
};

const int XX [4][3][2] = {
    {{0, 0}, {0, 1} ,{1, 1}},
    {{0, 0}, {1, 0} ,{0, 1}},
    {{0, 0}, {1, 0} ,{1, 1}},
    {{0, 0}, {1, 0} ,{1, -1}}
};

int h, w, total, count;
char in[20][21];
set<Tile> remain;


void getInput() {
    cin >> h >> w;
    cin.get();

    remain.clear();
    for (int i = 0; i < h; i++) {
        gets(in[i]);
        for (int j = 0; j < w; j++) {
            if (in[i][j] == '.') remain.insert(Tile(i, j));
        }
    }
}

bool canbe(int index, int row, int col) {
    for (int i = 0; i < 3; i++) {
        int r = row + XX[index][i][0];
        int c = col + XX[index][i][1];
        if (remain.find(Tile(r, c)) == remain.end()) return false;
    }
    return true;
}

void be(int index, int row, int col) {
    for (int i = 0; i < 3; i++) {
        int r = row + XX[index][i][0];
        int c = col + XX[index][i][1];
        remain.erase(Tile(r, c));
    }
}

void recover(int index, int row, int col) {
    for (int i = 0; i < 3; i++) {
        int r = row + XX[index][i][0];
        int c = col + XX[index][i][1];
        remain.insert(Tile(r, c));
    }
}

void cover() {
    if (remain.size() == 0) {
        count++;
        return;
    }

    Tile c = *remain.begin();
    for (int i = 0; i < 4; i++) {
        if (canbe(i, c.h, c.w)) {
            be(i, c.h, c.w);
            cover();
            recover(i, c.h, c.w);
        }
    }
}

void solve() {
    count = 0;
    total = remain.size();
    if (total % 3 != 0) {
        cout << 0 << endl;
        return;
    }

    cover();
    cout << count << endl;
}

int main(int argc, char *argv[]) {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
