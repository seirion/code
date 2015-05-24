// http://codeforces.com/contest/546/problem/C
// C. Soldier and Cards
#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;

void input(queue<int> &a) {
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push(t);
    }
}

void solve() {
}

int main() {
    queue<int> a, b;
    int n, c(0);
    cin >> n;
    input(a);
    input(b);

    set< pair<queue<int>, queue<int> > > ss;
    ss.insert(make_pair(a, b));

    while (!a.empty() && !b.empty()) {
        int x = a.front(); a.pop();
        int y = b.front(); b.pop();
        c++;

        if (x > y) {
            a.push(y); a.push(x);
        }
        else {
            b.push(x); b.push(y);
        }

        if (a.empty() || b.empty()) break;
        auto p = make_pair(a, b);
        if (ss.find(p) != ss.end()) break;
        ss.insert(p);
    }

    if (a.empty()) cout << c << " 2" << endl;
    else if (b.empty()) cout << c << " 1" << endl;
    else cout << -1 << endl;
    return 0;
}
