// http://codeforces.com/contest/546/problem/B
// B. Soldier and Badges
#include <iostream>

using namespace std;

int in[3001] = {0, };

int main() {
    int n, sum(0), mini(0x7FFFFFFF);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        in[t]++;
        sum += t;
    }

    int now(0), acc(0);
    for (int i = 1; i <= 3000; i++) {
        if (now == 0 && in[i] == 0) continue;
        else {
            acc += i;
            now += in[i] - 1;
        }
    }
    if (now > 0) {
        acc += (3001 + 3000 + now) * now / 2;
    }
    
    cout << acc - sum << endl;
    return 0;
}
