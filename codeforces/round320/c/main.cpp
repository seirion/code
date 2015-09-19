// codeforces round320
// http://codeforces.com/contest/579/problem/C
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a < b) cout << -1 << endl;
    else printf("%.10f\n", (a+b)/(2.*((a+b)/(2*b))));
    return 0;
}
