#include <iostream>

using namespace std;

int n;

void getInput() {
    cin >> n;
}

void solve() {
    unsigned int cache[1001];
    cache[0] = cache[1] = 1;
    cache[2] = 5;
    cache[3] = 11;

    for (int i = 4; i <= n; i++) {
        cache[i] = cache[i-1] + 5*cache[i-2] + cache[i-3] - cache[i-4];
    }
    static int count = 1;
    cout << count++ << " " << cache[n] << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
