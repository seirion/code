// https://www.facebook.com/hackercup/problem/798506286925018/
// Facebook Hacker Cup 2016 Round 1
// Coding Contest Creation
#include <iostream>
#include <cstdio>

using namespace std;

int n;
int in[100000];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];
}

void solve(int k) {
    int result = 0;
    int now = 1;

    for (int i = 1; i < n; i++) {

        if (now == 0) {
            now = 1;
            continue;
        }

        int diff = in[i] - in[i-1];
        if (diff <= 0 || (4-now) * 10 < diff) { // split
            result += 4 - now;
            now = 1;
        }
        else {
            int jump = (diff - 1) / 10;
            result += jump;
            now = (now + jump + 1) % 4;
        }
    }

    if (now != 0) result += (4-now);
    printf("Case #%d: %d\n", k, result);
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        input();
        solve(i);
    }

    return 0;
}
