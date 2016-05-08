// https://code.google.com/codejam/contest/4314486/dashboard#s=p0&a=2
// Problem A. Senate Evacuation
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int n;
int in[26];

void solve() {
    cin >> n;
    priority_queue<pair<int, int> > m;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sum += x;
        m.push(make_pair(x, i));
    }

    while (sum) {
        auto x = m.top(); m.pop();
        printf("%c", x.second + 'A');
        x.first--;
        m.push(x);
        sum--;

        x = m.top();
        if (sum < x.first << 1) {
            m.pop();
            printf("%c ", x.second + 'A');
            x.first--;
            m.push(x);
            sum--;
        }
        else cout << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}

