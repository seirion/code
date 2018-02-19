#include <iostream>
#include <string>

using namespace std;

string in[8];
int R, C; // position of 'k'
int out;

void find_k() {
    for (int rr = 0; rr < 8; rr++) for (int cc = 0; cc < 8; cc++) if (in[rr][cc] == 'k') {
        R = rr; C = cc; return;
    }
}

bool knight(int rr, int cc) {
    return (R == 1 && C == cc-2) || (R == 1 && C == cc+2) || (R == 2 && C == cc-1) || (R == 2 && C == cc+1);
}

bool no_one_row(int rr, int cc) {
    int a = min(C, cc);
    int b = max(C, cc);
    for (int x = a + 1; x < b; x++) if (in[rr][x] != '#') return false;
    return true;
}

bool no_one_col(int rr, int cc) {
    int a = min(R, rr);
    int b = max(R, rr);
    for (int x = a + 1; x < b; x++) if (in[x][cc] != '#') return false;
    return true;
}

bool rook(int rr, int cc) {
    if (R == rr && no_one_row(rr, cc)) return true;
    if (C == cc && no_one_col(rr, cc)) return true;
    return false;
}

bool bishop(int rr, int cc) {
    if (abs(R-rr) != abs(C-cc)) {
        return false;
    }

    int jr(1), jc(1);
    int a(R), b(rr), c(C), d(cc);

    if (a > b) jr *= -1;
    if (c > d) jc *= -1;

    int nr = a + jr;
    int nc = c + jc;
    while (nr != b && nc != d) {
        if (in[nr][nc] != '#') return false;
        nr += jr; nc += jc;
    }
    return true;
}

bool others() {
    for (int rr = 0; rr < 8; rr++) for (int cc = 0; cc < 8; cc++) {
        switch (in[rr][cc]) {
            case 'R':
                if (rook(rr,cc)) return true;
                break;
            case 'B':
                if (bishop(rr,cc)) return true;
                break;
            case 'Q':
                if (rook(rr,cc) || bishop(rr,cc)) return true;
                break;
        }
    }
    return false;
}

int go(int cc) {
    in[1][cc] = '#';
    int res = 0;
    if (knight(0, cc)) res++;
    if (rook(0, cc)) res += 2;
    if (bishop(0, cc)) res += 2;
    if (others()) {
        in[1][cc] = 'P';
        return 4;
    }

    in[1][cc] = 'P';
    return res;
}

int solve() {
    out = 0;
    find_k();
    for (int i = 0; i < 8; i++) {
        if (in[1][i] == 'P' && in[0][i] == '#') out += go(i);
    }
    return out;
}

int main() {
    int n; cin >> n;
    while (n--) {
        for (int i = 0; i < 8; i++) cin >> in[i];
        cout << solve() << endl;
    }
    return 0;
}
