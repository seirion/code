// https://www.facebook.com/hackercup/problem/169401886867367/
// Facebook Hacker Cup 2017 Qualification Round
// Lazy Loading
#include <iostream>
#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

int n;

void solve(int k) {
    deque<int> s;
    cin >> n;
    while (n--) {
        int x; cin >> x;
        s.push_back(x);
    }
    sort(s.begin(), s.end());

    int result = 0;
    while (!s.empty()) {
        int top = s.back();
        s.pop_back();
        
        if (50 <= top) { result++; continue; }
        int count = 1;
        while (!s.empty() && top*count < 50) {
            s.pop_front();
            count++;
        }
        if (50 <= top*count) result++;
    }
    printf("Case #%d: %d\n", k, result);
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}
