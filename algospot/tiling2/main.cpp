// http://algospot.com/judge/problem/read/TILING2
#include <iostream>

using namespace std;

int n;
long long cache[101];

void getInput() {
    cin >> n;
}

void solve() {
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 3;

    for (int i = 4; i <= 100; i++) {
        cache[i] = (cache[i-1] + cache[i-2]) % 1000000007LL;
    }
}

int main() {
    solve();

    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        getInput();
        cout << cache[n] << endl;
    }
    return 0;
}