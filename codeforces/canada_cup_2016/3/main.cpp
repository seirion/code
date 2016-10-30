#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

char out [2][13];

int main() {
    map<char, vector<int>> m;
    string str; cin >> str;

    for (int i = 0; i < 27; i++) {
        m[str[i]].push_back(i);
    }

    char me;
    vector<int> v;
    for (auto it : m) {
        if (it.second.size() == 2) { me = it.first; v = it.second; }
    }

    if (v[1] - v[0] == 1) {
        cout << "Impossible\n";
        return 0;
    }

    int left = v[1] - v[0] - 1;
    int right = 26 - left - 1;

    out[0][left/2] = me;
    int cur = v[0] + 1;
    int r = 0; int c = left/2 - 1;
    int inc = -1;

    int x = left;
    while (x--) {
        if (c == -1) {
            r =1; c = 0; inc = 1;
        }
        out[r][c] = str[cur++];
        c += inc;
    }

    r = 0; c = left / 2 + 1;
    cur = v[1] + 1;
    inc = 1;
    while (right--) {
        if (c == 13) {
            r = 1; c = 12; inc = -1;
        }
        out[r][c] = str[cur % 27];
        cur++;
        c += inc;
    }

    for (r = 0; r < 2; r++) {
        for (c = 0; c < 13; c++) {
            cout << out[r][c];
        }
        cout << endl;
    }
    return 0;
}
