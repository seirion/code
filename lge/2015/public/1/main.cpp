// LGE codejam 2015
// 1. ... .. ....
#include <iostream>
#include <string>

using namespace std;

enum { // directions
    NO, U, UR, R, DR, D, DL, L, UL,
};

int n;
string in;
int best_score;
string best;

int dtable [10][10] = { // direction table
    // 0   1   2   3   4   5   6   7   8   9
    { NO, NO, NO, NO, NO, NO, NO, UL,  U, UR }, // 0
    { NO, NO,  R, NO,  D, DR, NO, NO, NO, NO }, // 1
    { NO,  L, NO,  R, DL,  D, DR, NO, NO, NO }, // 2
    { NO, NO,  L, NO, NO, DL,  D, NO, NO, NO }, // 3
    { NO,  U, UR, NO, NO,  R, NO,  D, DR, NO }, // 4

    { NO, UL,  U, UR,  L, NO,  R, DL,  D, DR }, // 5
    { NO, NO, UL,  U, NO,  L, NO, NO, DL,  D }, // 6
    { DR, NO, NO, NO,  U, UR, NO, NO,  R, NO }, // 7
    {  D, NO, NO, NO, UL,  U, UR,  L, NO,  R }, // 8
    { DL, NO, NO, NO, NO, UL,  U, NO,  L, NO }  // 9
};

int score(/* const string &in */) {
    int total(0);
    int size = in.size();
    int direct(dtable[in[0]-'0'][in[1]-'0']), pre(in[1]-'0');

    if (in[0] == in[1]) total += 0;
    else if (direct != NO) total += 1;
    else total += 2;

    int pred = direct;
    for (int i = 2; i < size; i++) {
        int now(in[i]-'0');
        direct = dtable[pre][now];

        if (pre == now) { pred = NO; continue; } // total += 0;
        if (direct != NO && direct == pred) total += 1;
        else if (direct != NO) total += 2;
        else total += 3;

        pre = now;
        pred = direct;
    }

    return total;
}

void check() {
    int nscore = score();
    //cout << in << " :: " << nscore << endl;
    if (nscore < best_score) {
        best = in;
        best_score = nscore;
    }
}

void solve() {
    best_score = 0x7FFFFFFF;
    cin >> n;
    while(n--) {
        cin >> in;
        check();
    }
    cout << best << endl;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    } 
    return 0;
}
