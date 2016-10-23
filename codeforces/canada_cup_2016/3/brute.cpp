#include <iostream>
#include <string>
#include <set>

using namespace std;

const int SIZE = 27;
string str;
set<char> s;
char in[2][13] = {0, };


pair<int, int> where(char c, int row, int col) {
    int rs = max(0, row-1);
    int re = min(1, row+1);
    int cs = max(0, col-1);
    int ce = min(12, col+1);

    for (int rr = rs; rr <= re; rr++) {
        for (int cc = cs; cc <= ce; cc++) {
            if (rr == row && cc == col) continue;
            if (in[rr][cc] == c) return make_pair(rr, cc);
        }
    }
    return make_pair(-1, -1);
}

bool go(int index, char current, int row, int col) {
    if (index == SIZE) return true;
    char &now = str[index];

    if (s.find(now) == s.end()) { // not exist
        int rs = max(0, row-1);
        int re = min(1, row+1);
        int cs = max(0, col-1);
        int ce = min(12, col+1);

        for (int rr = rs; rr <= re; rr++) {
            for (int cc = cs; cc <= ce; cc++) {
                if (rr == row && cc == col) continue;
                if (in[rr][cc] != 0) continue;

                s.insert(now);
                in[rr][cc] = now;
                if (go(index+1, now, rr, cc)) return true;
                s.erase(now);
                in[rr][cc] = 0;
            }
        }
        return false;
    }
    else { // exist
        pair<int, int> p = where(now, row, col);
        if (p.first == -1) return false;
        return go(index+1, now, p.first, p.second);
    }
}

bool go() {
    s.insert(str[0]);
    for (int i = 0; i <= 6; i++) {
        in[0][i] = str[0];
        if (go(1, str[0], 0, i)) return true;
        in[0][i] = 0;
    }
    return false;
}

int main() {
    cin >> str;
    if (go()) {
        for (int i = 0; i < 13; i++) cout << in[0][i]; cout << endl;
        for (int i = 0; i < 13; i++) cout << in[1][i]; cout << endl;
    }
    else cout << "Impossible\n";
    return 0;
}
