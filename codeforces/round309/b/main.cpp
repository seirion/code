// http://codeforces.com/contest/554/problem/B
// B. Ohana Cleans Up
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    map<string, int> m;
    while (n--) {
        string s; cin >> s;
        m[s]++;
    }
    int maxi = 0;
    for (auto &it : m) {
        maxi = max(it.second, maxi);
    }
    cout << maxi << endl;
    return 0;
}
