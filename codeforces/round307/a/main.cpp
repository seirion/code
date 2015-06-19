// http://codeforces.com/contest/551/problem/A
// A. GukiZ and Contest
#include <iostream>
#include <set>
#include <functional>
#include <vector>
 
using namespace std;
 
int out[2001] = {0, };
 
int main() {
    int n, t, i(0); cin >> n;
    set< pair<int, int>, greater< pair<int, int> > > s;

    for (i = 0; i < n; i++) {
        cin >> t;
        s.insert(make_pair(t, i)); 
    } 

    i = 0;
    int j(1), pre(-1);
    for (auto p : s) {
        if (pre != p.first) {
            i += j;
            j = 1;
            pre = p.first;
        }
        else j++;
        out[p.second] = i;
    }

    for (i = 0; i < n; i++) {
        cout << out[i] << " ";
    }
    cout << endl;
    return 0;
}
