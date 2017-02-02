#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string s[50];
int row, col;
int aa[50], bb[50], cc[50];

int who(char ch) {
    if ('0' <= ch && ch <= '9') return 0;
    if ('a' <= ch && ch <= 'z') return 1;
    if (ch == '*' || ch == '#' || ch == '&') return 2;
    return 3;
}

int best = 1000;

void calc(int sel, vector<int> & v) {
    if (sel == 3) {
        best = min(best, aa[v[0]] + bb[v[1]] + cc[v[2]]);
        return;
    }

    if (sel == 0) {
        for (int i = 0; i < row; i++) {
            v.push_back(i);
            calc(1, v);
            v.pop_back();
        }
    }
    else if (sel == 1) {
        for (int i = 0; i < row; i++) {
            if (v[0] == i) continue;
            v.push_back(i);
            calc(2, v);
            v.pop_back();
        }
    }
    else { // 2
        for (int i = 0; i < row; i++) {
            if (v[0] == i || v[1] == i) continue;
            v.push_back(i);
            calc(3, v);
            v.pop_back();
        }
    }
}

int calc() {
    vector<int> v;
    calc(0, v);
    return best;
}

int main() {
    cin >> row >> col;
    for (int i = 0; i < row; i++) cin >> s[i];
    for (int i = 0; i < 50; i++) {aa[i] = bb[i] = cc[i] = 100; }

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            switch (who(s[r][c])) {
                case 0: // figure
                    aa[r] = min(aa[r], c);
                    aa[r] = min(aa[r], col - c);
                    break;
                case 1: // a - z
                    bb[r] = min(bb[r], c);
                    bb[r] = min(bb[r], col - c);
                    break;
                case 2: // * # &
                    cc[r] = min(cc[r], c);
                    cc[r] = min(cc[r], col - c);
                    break;
            }
        }
    }
    cout << calc() << endl;
    return 0;
}
