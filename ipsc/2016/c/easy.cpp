// https://ipsc.ksp.sk/2016/real/problems/c.html
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

const int MOD = 1e9 + 9;

int n;
int in[100000];

void swap(vector<int> &v, int a, int b) {
    v[a] ^= v[b] ^= v[a] ^= v[b];
}

bool put(map<vector<int>, pair<int, int>> &m, const vector<int> &now, int num, int count) {
    auto it = m.find(now);
    if (it == m.end()) { // not found
        m[now] = make_pair(num, count);
        return true;
    }
    else if (num < it->second.first) {
        it->second.first = num;
        it->second.second = count;
    }
    else if (num == it->second.first) {
        it->second.second = (it->second.second + count) % MOD;
        return true;
    }
    return false;
}

void solve() {
    cin >> n;
    vector<int> init(n), target(n);
    for (int i = 0; i < n; i++) {
        cin >> init[i];
        init[i]--; // make 0-based
        target[i] = i;
    }

    map<vector<int>, pair<int, int>> all; // permutation, #swap - count
    queue<pair<vector<int>, int>> q; // permutation, #swap
    put(all, init, 0, 1);
    q.push(make_pair(init, 0));

    int mini = 0x7FFFFFFF;

    while (!q.empty()) {
        auto now = q.front().first;
        auto num = q.front().second;
        q.pop();

        int count = all.find(now)->second.second;

        if (mini < num) continue; // not promising
        if (now == target) {
            continue;
        }

        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                swap(now, a, b);
                if (put(all, now, num+1, count)) {
                    q.push(make_pair(now, num+1));
                }
                swap(now, a, b); // roll-back
            }
        }
    }

    cout << all[target].second << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}

