// binary search
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

char s[200001], t[200001];
int in[200000];
int n, tsize;
set<int> v[26];
vector<int> vv;

int get(int ch, int from) {
    auto it = v[ch].lower_bound(from);

    while (it != v[ch].end()) {
        auto xx = lower_bound(vv.begin(), vv.end(), *it);
        if (xx == vv.end() || *xx != *it) return *it;
        it++;
    }
    return -1;
}

bool ok(int from) {
    for (int i = 0; i < tsize; i++) {
        int x = get(t[i] - 'a', from); 
        if (x == -1) return false;
        from = x + 1;
    }
    return true;
}

bool possible(int x) {
    vv.clear();
    for (int i = 0; i < x; i++) vv.push_back(in[i]);
    sort(vv.begin(), vv.end());
    return ok(0);
}

int binary_search() {
    int begin = 0;
    int end = n - tsize + 1; // [begin, end)

    while (begin < end) {
        int mid = (begin + end + 1) / 2;
        if (possible(mid)) begin = mid;
        else end = mid - 1;
    }
    return begin;
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
    cout << binary_search() << endl;
    return 0;
}
