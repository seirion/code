// codeforces round316
// http://codeforces.com/contest/570/problem/A
#include <iostream>

using namespace std;

int n, m;
int in[100];
int score[100] = { 0, };

int high_score() {
    int highindex(0);
    for (int i = 1; i < n; i++) {
        if (score[i] > score[highindex]) highindex = i;
    }
    return highindex;
}

int main() {
    int x, highindex, high;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> high; highindex = 0;
        for (int j = 1; j < n; j++) {
            cin >> x;
            if (x > high) { high = x; highindex = j; }
        }
        score[highindex]++;
    }

    cout << high_score() + 1 << endl;
    return 0;
}
