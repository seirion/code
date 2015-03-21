// http://codeforces.com/contest/527/problem/C
// C. Glass Carving

#include <cstdio>
#include <list>
#include <set>

using namespace std;

typedef long long int64;

int width, height, k;
set<int> row, col;
multiset<int> rr, cc;

void push(set<int> &s, multiset<int> &m, int in) {
    auto bound = s.lower_bound(in);
    int high = *bound;
    int low = *(--bound);
    s.insert(in);
    m.erase(m.find(high-low));
    m.insert(high - in);
    m.insert(in - low);
}

void solve() {
    char c;
    int in;
    scanf("%c %d\n", &c, &in);

    if (c == 'H') { // -
        push(row, rr, in);
    }
    else { // |
        push(col, cc, in);
    }
    printf("%I64d\n", (long long)(*rr.rbegin()) * (*cc.rbegin()));
}

int main() {
    scanf("%d %d %d\n", &width, &height, &k);
    col.insert(0); col.insert(width); 
    cc.insert(width);
    row.insert(0); row.insert(height); 
    rr.insert(height);

    while (k--) {
        solve();
    }
    return 0;
}
