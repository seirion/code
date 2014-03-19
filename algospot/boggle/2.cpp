// http://algospot.com/judge/problem/read/BOGGLE
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

class XY {
public:
    XY(int i, int j) : x(i), y(j) {}
    int x, y;
};

class mapping {
public:
    vector<XY> code[26]; // A ~ Z
    void clear() {
        for (int i = 0; i < 26; i++) code[i].clear();
    }
};

char in[5][5];
int n;
vector<string> str;
mapping m[5][5]; // memo


bool makeup(int r, int c) {

    int i = max(0, r - 1);
    int fromj = max(0, c - 1);
    int toi = min(4, r + 1);
    int toj = min(4, c + 1);
    for (; i <= toi; i++) {
        for (int j = fromj; j <= toj; j++) {
            if (i == r && j == c) continue;
            int id = in[i][j] - 'A';
            m[r][c].code[id].push_back(XY(i, j));
        }
    }

    return false;
}

void getInput() {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cin >> in[i][j];
            // clear
            m[i][j].clear();
        }
    }
    cin >> n;
    cin.get();
    char buffer[16];
    str.clear();
    for (i = 0; i < n; i++) {
        gets(buffer);
        str.push_back(string(buffer));
    }

    // makeup();
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            makeup(i, j);
        }
    }
}

bool each(const string &s, size_t index, int r, int c) {
    if (s.size() == index) {
        return true;
    }

    int id = s[index] - 'A';
    vector<XY> &current = m[r][c].code[id];
    if (!current.empty()) {
        size_t length = current.size();
        for (int i = 0; i < length; i++) {
            int xx = current[i].x;
            int yy = current[i].y;
            if (each(s, index + 1, xx, yy)) {
                return true;
            }
        }
    }

    return false;
}


bool check(const string &s) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (s[0] == in[i][j]) {
                if (each(s, 1, i, j)) {
                    return true;
                }
            }
        }
    }

    return false;
}

void solve() {
    for (int i = 0; i < n; i++) {
        cout << str[i];
        if (check(str[i])) {
            cout << " YES" << endl;
        }
        else cout << " NO" << endl;
    }
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
