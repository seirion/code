// https://www.hackerrank.com/contests/w19/challenges/two-robots
// Two Robots
#include <iostream>
#include <cstdlib>

using namespace std;

int m, n;
int in[1000][2];
int best;

void input() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i][0] >> in[i][1];
    }
    best = 0x0FFFFFFF;
}

void aaa(int a, int b, int index, int dist) {
    if (index == n) {
        best = min(best, dist);
    }
    if (best <= dist) return;

    int dist1 = (a == -1 ? 0 : abs(in[index][0] - a)) + abs(in[index][0] - in[index][1]);
    int dist2 = (b == -1 ? 0 : abs(in[index][0] - b)) + abs(in[index][0] - in[index][1]);

    aaa(in[index][1], b, index+1, dist+dist1);
    aaa(a, in[index][1], index+1, dist+dist2);
}

void solve() {
    aaa(-1, -1, 0, 0);
    cout << best << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}
