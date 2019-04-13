#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class T { public: // trie
    T(char c_): c(c_) {}
    bool terminal = false;
    char c;
    vector<T> child;
};

void put(T &tree, string str, int index = 0) {
    char c = str[index];
    auto &child = tree.child;

    if (child.empty() || child.back().c != str[index]) {
        child.push_back(T(c));
    }

    if (str.size() == index + 1) { // finish
        child.back().terminal = true;
    } else {
        put(child.back(), str, index + 1);
    }
}

int unused(T &tree) {
    if (tree.child.empty()) return 1;

    int r = 0;
    if (tree.terminal) r++;
    for (auto c: tree.child) {
        r += unused(c);
    }
    if (tree.c != '_' && r >= 2) r -= 2;
    return r;
}

void solve() {
    int n; cin >> n;
    vector<string> in(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        reverse(in[i].begin(), in[i].end());
    }
    sort(in.begin(), in.end());

    T tree('_'); // root
    for (auto s : in) put(tree, s);


    // dfs
    cout << n - unused(tree) << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
