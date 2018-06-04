#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
bool visit[1001] = {0, };

void solve() {
    int n; cin >> n;
    v.resize(n);
    cout << v.size() << endl;
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int r(0), c(0);
    for (int k = 0; k < n; k++) {
        if (visit[k]) continue;
        visit[k] = true;
        r++; c = 1;

        for (int i = k + 1; i < n; i++) {
            if (visit[i]) continue;
            if (c <= v[i]) { // pile
                c++;
                visit[i] = true;
            }
        }
    }

    cout << r << endl;
}

int main() {
    solve();
    return 0;
}
