// https://code.google.com/codejam/contest/6224486/dashboard#s=p1
// Problem B. Infinite House of Pancakes

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solve() {
    vector<int> in;
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        in.push_back(t);
    }
    sort(in.begin(), in.end());

    const int LIMIT = *in.rbegin();
    int answer = 1000;
    for (int i = 1; i <= LIMIT; i++) {
        int minute = i;

        for (auto it = upper_bound(in.begin(), in.end(), i); it != in.end(); it++) {
            minute += (*it - 1) / i;
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

