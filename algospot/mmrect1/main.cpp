// http://algospot.com/judge/problem/read/MMRECT1
#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

map<int, set<int> > xy;

int n;


void getInput() {
    xy.clear();

    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        xy[x].insert(y);
    }
}

void solve() {
    int mini(3000000), maxi(0);

    map<int, set<int> >::iterator it = xy.begin();
    while (it != xy.end()) {
        int x, y, w;
        x = it->first;
        set<int> &s = it->second;
        set<int>::const_iterator i = s.begin();
        for (; i != s.end(); i++) {
            y = *i;
            set<int>::const_iterator j;
            for (j = i, j++; j != s.end(); j++) {
                w = *j - *i; // length
                if (mini <= w && w <= maxi) continue;
                if (xy.count(x+w) && xy[x+w].count(y) && xy[x+w].count(y+w)) {
                    mini = min(mini, w);
                    maxi = max(maxi, w);
                }
            }
        }
        it++;
    }
    cout << mini << " " << maxi << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
