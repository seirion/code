#include <iostream>
#include <queue>

using namespace std;

int value(pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.second == p2.second) return 0x7FFFFFFF;
    return p1.first + p2.first;
}

int main() {
    int n; cin >> n;
    priority_queue<pair<int, int>> a, b;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push(make_pair(x, i));
        if (a.size() > 2) a.pop();
    }

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        b.push(make_pair(x, i));
        if (b.size() > 2) b.pop();
    }

    auto a1 = a.top(); a.pop();
    auto a2 = a.top();
    auto b1 = b.top(); b.pop();
    auto b2 = b.top();

    int x = min(value(a1, b1), value(a1, b2));
    int y = min(value(a2, b1), value(a2, b2));
    cout << min(x, y) << endl;
    return 0;
}
