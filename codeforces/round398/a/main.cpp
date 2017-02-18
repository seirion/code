#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int n;
vector<pair<int, int>> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(make_pair(x, i));
    }

    sort(v.begin(), v.end(), greater<pair<int,int>>());

    //for (auto x : v) { cout << x.first <<  " " << x.second << endl; }
    int now = 0;
    for (auto x : v) {
        while (now < x.second) { now++; cout << endl; }
        cout << x.first << " ";
    }
    cout << endl;

    return 0;
}

