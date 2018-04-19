#include <iostream>
#include <map>

using namespace std;

long long total;
long long in[26];
map<long long, int> a, b;

int forward(int start) {
    int i; for (i = start; i < 26; i++) if (0 < in[i]) break;
    return i;
}

int backward(int start) {
    int i; for (i = start; 0 <= i; i--) if (0 < in[i]) break;
    return i;
}

void input() {
    total = 0; a.clear(); b.clear();
    for (int i = 0; i < 26; i++) {
        cin >> in[i];
        total += in[i];
    }

    int from = forward(0);
    int to = backward(25);
    while (from <= to) {
        if (from == to) {
            b[to] += in[to]/2; in[to] -= in[to]/2;
            a[from] += in[from]; in[from] = 0;
        } else {
            int num = min(in[from], in[to]);
            a[from] += num; in[from] -= num;
            b[to] += num; in[to] -= num;
        }

        from = forward(from);
        to = backward(to);
    }

    if (total % 2 == 0) {
        b.begin()->second--;
    }
}

void solve() {
    long long r = 0;
    auto aa = a.begin();
    auto bb = b.begin();
    long long left = aa->first; aa->second--;
    while (aa != a.end() && bb != b.end()) {
        if (aa->second == 0) { aa++; continue; }
        if (bb->second == 0) { bb++; continue; }
        if (bb->first <= left) { bb++; continue; }
        if (bb->first <= aa->first) { bb++; continue; }

        int num = min(aa->second, bb->second);
        r += num;
        aa->second -= num;
        bb->second -= num;
        left = aa->first;
    }
    cout << r << endl;
}

int main() {
    int t; cin >> t;
    while (t--) { input(); solve(); }
    return 0;
}
