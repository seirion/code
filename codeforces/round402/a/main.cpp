#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;
    multiset<int> a, b;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;

        auto it = a.find(x);
        if (it != a.end()) {
            a.erase(it);
        } else {
            b.insert(x);
        }
    }
    
    map<int, int> m;
    for (int x : a) m[x]++;
    for (int x : b) m[x]++;

    int r = 0;
    for (auto it : m) {
        if (it.second % 2 == 1) goto OUT;
        r += (it.second / 2);
    }
    cout << r / 2 << endl;
    return 0;

OUT:
    cout << -1 << endl;
    return 0;
}

