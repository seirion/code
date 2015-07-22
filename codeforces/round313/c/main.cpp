// codeforces round313
// http://codeforces.com/contest/560/problem/C
#include <iostream>

using namespace std;

int in[6];

int s(int n) {
    return n * (n+1) - n;
}

int main() {
    cin >> in[0] >> in[1] >> in[2] >> in[3] >> in[4] >> in[5];

    cout << s(in[0] + in[1] + in [5]) - s(in[1]) - s(in[3]) - s(in[5]) << "\n";
    return 0;
}
