// https://www.hackerrank.com/contests/world-codesprint-7/challenges/episode-recording
// Recording Episodes
#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


int n, best, besti;
int in[101][4];

bool promissing(int now) {
    return best < (n - now);
}

pair<int, int> get(int index) { // *2 index
    if (index & 1) { // repeat
        return make_pair(in[index/2][2], in[index/2][3]);
    }
    else { // live
        return make_pair(in[index/2][0], in[index/2][1]);
    }
}

bool possible(set<pair<int, int>> &out, int index) { // *2 index

    pair<int, int> add = get(index);

    if (out.rbegin()->second < add.first) return true;

    for (auto p : out) {
        if (add.second < p.first) return true;
        if (p.first <= add.second || add.first <= p.second) return false;
    }
    return true;
}

void go(set<pair<int, int>> &out, int index, int len) { // real index
    if (best < len) {
        besti = index - len;
        best = len;
    }

    if (n <= index) return;
    if (len + (n-index) <= best) return;

    if (possible(out, index*2)) {
        pair<int, int> pp = get(index*2);
        out.insert(pp);
        go(out, index+1, len+1);
        out.erase(pp);
    } 

    if (possible(out, index*2+1)) {
        pair<int, int> pp = get(index*2+1);
        out.insert(pp);
        go(out, index+1, len+1);
        out.erase(pp);
    } 
}

void check() {

    for (int i = 0; i < n; i++) {
        set<pair<int, int>> out;
        out.insert(make_pair(in[i][0], in[i][1]));
        if (promissing(i)) go(out, i+1, 1);

        out.clear();
        out.insert(make_pair(in[i][2], in[i][3]));
        if (promissing(i)) go(out, i+1, 1);
    }
}

int main() {
    int ep; cin >> ep;
    while (ep--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> in[i][0] >> in[i][1] >> in[i][2] >> in[i][3];
        }

        best = 1;
        besti = 0;
        check();

        cout << besti + 1 << " " << besti + best << endl;
    }
    return 0;
}
