#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

char s[200001], t[200001];
int in[200000];
vector<int> me;
int n, tsize;
set<int> v[26];

int get(int ch, int from) {
    auto it = v[ch].lower_bound(from);
    if (it == v[ch].end()) return -1;
    return *it;
}

bool ok(int i, int from) {
    for (; i < tsize; i++) {
        int x = get(t[i] - 'a', from); 
        if (x == -1) return false;
        if (me[i] == x) break;
        me[i] = x;
        from = x + 1;
    }
    return true;
}

int check() {
    int r = 0;
    for (int i = 0; i < n; i++, r++) {
        int &x = in[i];
        v[s[x] - 'a'].erase(x);

        auto it = lower_bound(me.begin(), me.end(), x);
        if (it != me.end() && *it == x && !ok(it - me.begin(), *it + 1)) return r;
    }
    return r;
}

int main() {
    gets(s); gets(t);
    n = strlen(s);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        in[i]--;

        v[s[i]-'a'].insert(i);
    }

    tsize = strlen(t);
    me.resize(tsize, -1);
    ok(0, 0);
    cout << check() << endl;
    return 0;
}
