#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int LIMIT = 10000;
int n, k; // sheep, stick
bool m[LIMIT+1][LIMIT+1] = {false, }; // memoization

// 1 - 1
// 2 - 5, 10
// 3 - 4, 9
void build() {
    vector<pair<int, int>> v;
    v.push_back(make_pair(1, 1));
    v.push_back(make_pair(2, 5));
    v.push_back(make_pair(2, 10));
    v.push_back(make_pair(3, 4));
    v.push_back(make_pair(3, 9));

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        auto current = q.front(); q.pop();
        int a = current.first;
        int b = current.second;

        for (auto &it : v) {
            int aa = it.first;
            int bb = it.second;
            if (a+aa <= LIMIT && b+bb <= LIMIT && !m[a+aa][b+bb]) {
                m[a+aa][b+bb] = true;
                q.push(make_pair(a+aa, b+bb));
            }
        }
    }
}

void solve() {
    cin >> n >> k;

    if (m[k][n]) cout << "O\n";
    else cout << "X\n";
}

int main() {
    build();
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
