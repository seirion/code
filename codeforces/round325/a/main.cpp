// codeforces round325
// http://codeforces.com/contest/586/problem/A
#include <iostream>

using namespace std;

int in[101] = {0, };

int main() {
    int n, c(0);
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> in[i];

    if (in[1] == 1) c++;

    for (int i = 2; i <= n; i++) {
        if (in[i] == 1) {
            if (in[i-1] == 1) c++;
            else if (in[i-2] == 1) c += 2;
            else c++;
        }
    }

    cout << c << endl;
    return 0;
}
