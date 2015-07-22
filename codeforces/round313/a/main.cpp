// codeforces round313
// http://codeforces.com/contest/560/problem/A
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int in[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    sort(in, in+n);
    if (in[0] == 1) cout << "-1\n";
    else cout << "1\n";
    return 0;
}
