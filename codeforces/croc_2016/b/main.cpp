// http://codeforces.com/contest/644/problem/B
// CROC 2016 - Qualification
// B. Processing Queries
#include <iostream>
#include <queue>

using namespace std;

int n, s; // s : queue size
long long intime[200000];
long long len[200000];

int main() {
    cin >> n >> s;
    s++;
    for (int i = 0; i < n; i++) {
        cin >> intime[i] >> len[i];
    }

    queue<long long> q;

    for (int i = 0; i < n; i++) {
        while (!q.empty() && q.front() <= intime[i]) {
            q.pop();
        }
        if (q.empty()) {
            cout << intime[i] + len[i] << " ";
            q.push(intime[i] + len[i]);
            continue;
        }
        if (q.size() < s) {
            cout << q.back() + len[i] << " ";
            q.push(q.back() + len[i]);
        }
        else {
            cout << "-1 ";
        }
    }

    cout << endl;
    return 0;
}
