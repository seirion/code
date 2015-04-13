// https://code.google.com/codejam/contest/6224486/dashboard#s=p1
// Problem B. Infinite House of Pancakes

#include <cstdio>
#include <iostream>

using namespace std;

int in[1001];

int solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    int answer = 1000;
    for (int i = 1; i <= 1000; i++) {
        int minute = i;
        for (int j = 0; j < n; j++) {
            minute += (in[j] - 1) / i;
        }
        answer = min(answer, minute);
    }
    return answer;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: %d\n", i, solve());
    }
}

