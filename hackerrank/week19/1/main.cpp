// https://www.hackerrank.com/contests/w19/challenges/fix-the-cycles
// Fix the Cycles
#include <iostream>

using namespace std;

int in[6];

int x() { return in[1] + in[2] + in[3] + in[0]; }
int y() { return in[1] + in[5] + in[0]; }
int z() { return in[4] + in[3] + in[0]; }

int main() {

    for (int i = 0; i < 6; i++) cin >> in[i];

    int res;
    for (res = 0; res <= 120; res++) {
        for (int index = 0; index < 6; index++) {
            in[index] += res;
            if (0 <= x() && 0 <= y() && 0 <= z()) {
                cout << res << endl;
                return 0;
            }
            in[index] -= res;
        }
    }

    cout << -1 << endl;
    return 0;
}
