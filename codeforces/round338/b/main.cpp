// http://codeforces.com/contest/615/problem/B
// B. Longtail Hedgehog
#include <iostream>
#include <set>
#include <map>

using namespace std;

int n, m;
set<int> t[100001];
int depth[100001] = {0, };
map<int ,int> mm;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        t[max(x,y)].insert(min(x,y));
        mm[x]++;
        mm[y]++;
    }
    
    long long maxi = 0;
    for (int i = 1; i <= n; i++) {
        //if (t[i] != 0) depth[i] = depth[t[i]] + 1;
        //else depth[i] = 1;

        if (t[i].empty()) depth[i] = 1;
        else {
            for (int x : t[i]) {
                depth[i] = max(depth[i], depth[x]+1);
            }
        }
        maxi = max(maxi, (long long)depth[i] * mm[i]);
    }

    cout << maxi << endl;
    return 0;
}
