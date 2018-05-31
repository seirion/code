#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

char in[103][103] = {0, };
int row, col;
string str; // 찾아야 할 입력
int len;

void input() {
    cin >> str;
    scanf("%d %d\n", &row, &col);
    len = str.size();

    for (int r = 1; r <= row; r++) gets(&in[r][1]);
}


bool go(int r, int c, int dr, int dc) { // delta-row , delta-col
    for (int x = 0; x < len; x++, r += dr, c += dc) {
        if (str[x] != in[r][c]) return false;
    }
    return true;
}

bool right(int r, int c) { return go(r, c, 0, 1); }
bool left(int r, int c) { return go(r, c, 0, -1); }
bool down(int r, int c) { return go(r, c, 1, 0); }
bool up(int r, int c) { return go(r, c, -1, 0); }
bool up_right(int r, int c) { return go(r, c, -1, 1); }
bool up_left(int r, int c) { return go(r, c, -1, -1); }
bool down_right(int r, int c) { return go(r, c, 1, 1); }
bool down_left(int r, int c) { return go(r, c, 1, -1); }

bool check(int r, int c) {
    if (right(r, c) || left(r, c) || down(r, c) || up(r, c) ||
            up_right(r, c) || up_left(r, c) ||
            down_right(r, c) || down_left(r, c)) return true;
    return false;
}

void solve() {
    for (int r = 1; r <= row; r++) {
        for (int c = 1; c <= col; c++) {
            if (check(r, c)) {
                cout << 1 << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
}

int main() {
    input();
    solve();
    return 0;
}
