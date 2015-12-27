// http://codeforces.com/contest/610/problem/B
#include <iostream>

using namespace std;

int n;
int in[200000];

int main() {
    int mini = 0x7FFFFFFF;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        mini = min(mini, in[i]);
    }

    int maxi = 0;
    int now = 0;
    for (int i = 0; i < n*2; i++) {
        if (in[i%n] == mini) {
            maxi = max(maxi, now);
            now = 0;
        }
        else {
            now++;
        }
    }

    cout << (long long)mini * n + maxi << endl;
    return 0;
}
