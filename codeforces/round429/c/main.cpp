#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class T { public:
    int v, i;
    bool operator <(const T &x) const {
        return v < x.v;
    }
};

int n;

int main() {
    cin >> n;
    vector<int> a(n), out(n);
    vector<T> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i].v;
        b[i].i = i;
    }

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        int index = b[i].i;
        out[index] = a[i];
    }

    for (auto x : out) cout << x << " ";
    cout << endl;
    return 0;
}

