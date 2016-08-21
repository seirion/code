// http://codeforces.com/contest/707/problem/D
#include <iostream>
#include <vector>

using namespace std;

int row, col, query, current(0);
vector<bool> s(1001 * 1001, false);
int in[100001][3];
vector<int> child[100001];
int out [100001] = {0, }; // output


bool put(int index, int r, int c) {
    bool valid = !s[r*col+c];
    s[r*col+c] = true;
    if (valid) current++;
    return valid;
}

bool remove(int index, int r, int c) {
    bool valid = s[r*col+c];
    s[r*col+c] = false;
    if (valid) current--;
    return valid;
}

void invert(int index, int r) {
    int valid = 0;
    for (int i = r * col, end = (r+1) * col; i < end; i++) {
        if (s[i]) {
            s[i] = false;
            valid--;
        }
        else {
            s[i] = true;
            valid++;
        }
    }
    current += valid;
}

void dfs(int x) {
    bool valid = true;

    switch (in[x][0]) {
        case 1: valid = put(x, in[x][1], in[x][2]); break;
        case 2: valid = remove(x, in[x][1], in[x][2]); break;
        case 3: invert(x, in[x][1]); break;
        default: break;
    }
    out[x] = current;
    if (in[x][0] == 4) out[x] = out[in[x][1]];

    for (int c : child[x]) {
        dfs(c);
    }

    // roll-back
    if (!valid) in[x][0] = 0;

    switch (in[x][0]) {
        case 1: remove(x, in[x][1], in[x][2]); break;
        case 2: put(x, in[x][1], in[x][2]); break;
        case 3: invert(x, in[x][1]); break;
        default: break;
    }
}

int main() {
    cin >> row >> col >> query;

    // input
    for (int i = 1; i <= query; i++) {
        cin >> in[i][0] >> in[i][1];
        if (in[i][0] <= 2) cin >> in[i][2];

        if (in[i][0] != 4) { in[i][1]--; in[i][2]--; } // 0-based index
    }

    // make tree
    child[0].push_back(1);
    int p = 0; // parent
    for (int i = 1; i <= query; i++) {
        if (in[i][0] == 4) {
            p = in[i][1];
            child[p].push_back(i);
        }
        else {
            child[p].push_back(i);
            p = i;
        }
    }

    // dfs
    dfs(0);

    for (int i = 1; i <= query; i++) cout << out[i] << endl;
    return 0;
}
