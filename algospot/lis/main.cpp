// http://algospot.com/judge/problem/read/LIS
#include <iostream>
#include <cstring>


using namespace std;

int in[500];
int r[500];
int size;

void getInput() {
    cin >> size;
    for (int i = 0; i < size; i++) cin >> in[i];
    memset(r, 0, sizeof(int) * 500);
}

int num(int to) {
    int mi = -1; // max index
    for (int i = 0; i < to; i++) {
        if (in[i] < in[to] && r[mi] < r[i]) {
            mi = i;
        }
    }
    if (mi == -1) return 1;
    return r[mi] + 1;
}

void solve() {
    getInput();

    r[0] = 1;
    int m = 1;
    for (int i = 1; i < size; i++) {
        r[i] = num(i);
        m = max(m, r[i]);
    }

    cout << m << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) solve();
    return 0;
}
