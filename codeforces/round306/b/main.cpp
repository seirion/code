// http://codeforces.com/contest/550/problem/B
// B. Preparing Olympiad
#include <iostream>

using namespace std;

int n, low, high, md, c;
int in[16];

void ccc(int index, int sum, int cmin, int cmax) {
    if (index == n) {
        if (low <= sum && sum <= high && md <= (cmax-cmin)) c++;
        return;
    }
    if (sum > high) return;

    ccc(index+1, sum, cmin, cmax);
    ccc(index+1, sum+in[index], min(cmin, in[index]), max(cmax, in[index]));
}

int main() {
    cin >> n >> low >> high >> md;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    c = 0;
    ccc(0, 0, 0x0FFFFFFF, 0);
    cout << c << endl;
    return 0;
}
