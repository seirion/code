// https://ipsc.ksp.sk/2016/real/problems/a.html
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check(vector<string> & v, int &a, int &b) {
    for (a = 0; a < 10; a++) {
        for (b = 0; b < 10; b++) {
            if (a == b) continue;
            if (v[a][3] == v[b][0]) return 1;
        }
    }
    for (a = 0; a < 10; a++) {
        for (b = 0; b < 10; b++) {
            if (a == b) continue;
            if (v[a][2] == v[b][0] && v[a][3] == v[b][1]) return 2;
        }
    }

    for (a = 0; a < 10; a++) {
        for (b = 0; b < 10; b++) {
            if (a == b) continue;
            if (v[a][1] == v[b][0] && v[a][2] == v[b][1] && v[a][3] == v[b][2]) return 3;
        }
    }
    for (a = 0; a < 10; a++) {
        for (b = 0; b < 10; b++) {
            if (a == b) continue;
            if (v[a] == v[b]) return 4;
        }
    }
}

void solve() {
    vector<string> v;
    bool ok = true;
    for (int i = 0; i < 10; i++) {
        string s; cin >> s;
        v.push_back(s);
    }

    int a, b;
    int r = check(v, a, b);

    if (r == 1) {
        v[a] = v[a].substr(0, 3);
        cout << v[a] << v[b];
    } else if (r == 2) {
        v[a] = v[a].substr(0, 2);
        cout << v[a] << v[b];
    } else if (r == 3) {
        v[a] = v[a].substr(0, 1);
        cout << v[a] << v[b];
    } else {
        cout << v[a];
    }

    for (int i = 0; i < 10; i++) {
        if (i != a && i != b) cout << v[i];
    }

    for (int i = 1; i < r; i++) cout << "X";
    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) { solve(); }
    return 0;
}
