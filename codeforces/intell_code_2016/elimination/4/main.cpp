#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n;
set<int> s, temp;

bool ok(int x) {
    while (true) {
        x >>= 1;
        if (x == 0) return false;
        if (s.find(x) == s.end() && temp.find(x) == temp.end()) return true;
    }
    return false;
}

void refine(int x) {
    s.erase(x);

    while (true) {
        x >>= 1;
        if (x == 0) return;
        if (s.find(x) == s.end() && temp.find(x) == temp.end()) {
            s.insert(x);
            break;
        }
    }
}

bool del(int x) {
    if (s.empty() || x < *s.begin()) return false;
    if (ok(x)) {
        refine(x);
        return true;
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }

    while (!s.empty()) {
        int now = *s.rbegin();
        if (!del(now)) {
            s.erase(now);
            temp.insert(now);
        }
    }

    for (int x : temp) cout << x << " ";
    return 0;
}
