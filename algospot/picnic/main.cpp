// http://algospot.com/judge/problem/read/PICNIC
#include <iostream>
#include <cstring>

using namespace std;

int n;
int m;
bool c[10][10]; // connection

void getInput() {
    memset(c, 0, sizeof(bool) * 10 * 10);

    int a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (b > a) c[a][b] = true;
        else c[b][a] = true;
    }
}

int getPair(int s) {
    if (s == 0) { // empty
        return 1;
    }

    int from = __builtin_ctz(s);
    s &= s - 1;

    int remain = s;
    int count = 0;
    while (remain) {
        int to = __builtin_ctz(remain);
        if (c[from][to]) {
            count += getPair(s & ~(1 << to));
        }

        remain &= remain - 1;
    }

    return count;
} 
void solve() {
    cout << getPair((0x1 << n) - 1) << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
