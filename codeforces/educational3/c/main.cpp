// http://codeforces.com/contest/609/problem/C
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int in[100001];

int main() {
    int n, i;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> in[i];
    }

    int sum = accumulate(in, in+n, 0);
    int average = sum / n;
    int remain = sum % n;
    int to = n - remain;

    sort(in, in + n);

    int all = 0;
    for (i = 0; i < to; i++) {
        all += abs(average - in[i]);
    }

    for (; i < n; i++) {
        all += abs(average + 1 - in[i]);
    }

    cout << all/2 << endl;
    return 0;
}
