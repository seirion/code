#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, s, t, g, seed, p;
long long in[10000001];
int m[10000001];

int main() {
    memset(m, 0x7F, sizeof(m));
    cin >> n >> s >> t >> in[0] >> g >> seed >> p;

    for (int i = 1; i < n; i++) {
        in[i] = (in[i-1] * g + seed) % p;
    }

    queue<int> q;
    q.push(s);
    m[s] = 0;

    while (!q.empty()) {
        int now = q.front(); q.pop();
        if (now == t) break;

        int v = in[now]; // max jump
        int c = m[now] + 1; // count
        while (0 < v) {
            int index = (now+v) % n;
            if (c < m[index]) {
                m[index] = c;
                q.push(index);
            }

            index = (now-v+n) % n;
            if (c < m[index]) {
                m[index] = c;
                q.push(index);
            }
            v--;
        }
    }

    if (m[t] == 0x7F7F7F7F) m[t] = -1;
    cout << m[t] << endl;
    return 0;
}
