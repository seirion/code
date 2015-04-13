// https://code.google.com/codejam/contest/6224486/dashboard#s=p1
// Problem B. Infinite House of Pancakes

#include <cstdio>
#include <iostream>
#include <map>

using namespace std;


int solve() {
    map<int, int> in;
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        in[t]++;
    }

    const int LIMIT = in.rbegin()->first;
    int answer = 1000;
    for (int i = 1; i <= LIMIT; i++) {
        int minute = i;

        for (auto it = in.upper_bound(i); it != in.end(); it++) {
            minute += ((it->first - 1) / i) * it->second;
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

