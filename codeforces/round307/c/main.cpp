// http://codeforces.com/problemset/problem/551/C
// C. GukiZ hates Boxes
#include <iostream>
#include <vector>

using namespace std;

int n, m;
long long low(2), high(0);
int in[500000];

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        high += in[i];
    }
    high += n;
}

bool possible(long long mid) {
    vector<int> t(in, in+n); // copy
    int x = 0;
    for (int i = 0; i < m; i++) {
        long long remain(mid);
        while (x < n && t[x] == 0) x++; // find none-zero from left
        remain -= (x + 1); // move to x
        while (remain > 0 && x < n) { 
            if (remain >= t[x]) {
                remain -= (t[x] + 1); t[x] = 0;
                x++;
            }
            else {
                t[x] -= remain;
                break;
            }
        }
        while (x < n && t[x] == 0) x++;
        if (x == n) return true;
    }
    return (x == n);
}

void solve() {

    while (low < high) {
        long long mid = (low + high) >> 1;
        if (possible(mid)) high = mid;
        else low = mid +1;
    }

    cout << high << endl;
}

int main() {
    input(); solve();
}
