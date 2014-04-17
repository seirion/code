// http://algospot.com/judge/problem/read/BOGGLE
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


char in[5][5];
int n;
char str[10][11];
set<string> mem[5][5];

void getInput() {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cin >> in[i][j];
        }
    }
    cin >> n;
    cin.get();
    char buffer[16];
    for (i = 0; i < n; i++) {
        gets(str[i]);
    }
}

void put(char *buffer, set<string> &node, int r, int c, int length) {
    node.insert(string(buffer));
    if (length >= 5) return;

    int i = max(0, r - 1);
    int fromj = max(0, c - 1);
    int toi = min(4, r + 1);
    int toj = min(4, c + 1);
    for (; i <= toi; i++) {
        for (int j = fromj; j <= toj; j++) {
            if (!(r == i && c == j)) {
                buffer[length] = in[i][j];
                buffer[length + 1] = '\0';
                put(buffer, node, i, j, length + 1);
            }
        }
    }

}

void makeup() {
    char buffer[6];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            buffer[0] = in[i][j];
            buffer[1] = '\0';
            put(buffer, mem[i][j], i, j, 1);
        }
    }
}

bool exist(const string &ss) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (ss[0] == in[i][j]) {
                set<string> &_set = mem[i][j];
                if (find(_set.begin(), _set.end(), ss) != _set.end()) {
                    return true;
                }
            }
        }
    }
    return false;
}

void search(int index) {
    int s = (int)strlen(str[index]);
    int i = max(0, s - 5);

    while (i >= 0) {
        str[index][s]= '\0';
        string ss(str[index] + i);

        if (!exist(ss)) {
            cout << " NO" << endl;
            return;
        }
        s--;
        i--;
    }
    cout << " YES" << endl;
}

void solve() {
    makeup();
    for (int i = 0; i < n; i++) {
        cout << str[i];
        search(i);
    }
}

void clear() {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            mem[i][j].clear();
        }
    }
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
