// https://www.hackerrank.com/contests/w22/challenges/polygon-making
// Making Polygons
#include <iostream>
#include <algorithm>

int n;
int in[50];

using namespace std;

int main() {
    int sum(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        sum += in[i];
    }
    sort(in, in+n);
    if (sum - in[n-1] <= in[n-1]) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}
