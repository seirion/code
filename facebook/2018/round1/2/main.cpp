// https://www.facebook.com/hackercup/problem/232395994158286/
// Facebook Hacker Cup 2018 Round 1
// Ethan Traverses a Tree
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstring>

using namespace std;

int n, k;
int in[2002][2]; // left and right
int p[2002];
vector<int> a, b; // pre-order

void input() {
    memset(p, 0, sizeof(p));
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> in[i][0] >> in[i][1];
}

void pre(int x) {
    a.push_back(x);
    if (in[x][0] != 0) pre(in[x][0]);
    if (in[x][1] != 0) pre(in[x][1]);
}

void post(int x) {
    if (in[x][0] != 0) post(in[x][0]);
    if (in[x][1] != 0) post(in[x][1]);
    b.push_back(x);
}

int root(int x) {
    if (p[x] == 0 || p[x] == x) return x;
    p[x] = root(p[x]);
    return p[x];
}

bool ok() {
    auto aa = a.begin();
    auto bb = b.begin();
    while (aa != a.end() && bb != b.end()) {
        int x = root(*aa);
        int y = root(*bb);

        p[y] = x;
        aa++; bb++;
    }

    //cout << endl; for (auto x: a) cout << x << " "; cout << endl;
    //for (auto x: b) cout << x << " "; cout << endl;
    //for (int i = 1; i <= n; i++) cout << i << " " << root(i) << endl; cout << "--\n";
    set<int> ss;
    for (int i = 1; i <= n; i++) {
        ss.insert(root(i));
    }
    if (k <= ss.size()) {
        for (int i = 1; i <= n; i++) {
            int rr = root(i);
            if (k < rr) rr = k;
            cout << rr << " ";
        }
        cout << endl;
        return true;
    }
    else {
        return false;
    }
}

void solve(int no) {
    cout << "Case #" << no << ": ";
    a.clear(); b.clear();
    pre(1);
    post(1);

    if (ok()) {
    }
    else {
        cout << "Impossible\n";
    }
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        input();
        solve(i);
    }
    return 0;
}
