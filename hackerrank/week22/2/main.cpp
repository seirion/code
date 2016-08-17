// https://www.hackerrank.com/contests/w22/challenges/polygon-making
// Making Polygons
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    sort(a.begin(), a.end());

    if (a.size() == 1) cout << 2 << endl;
    else if (a.size() == 2 && a[0] == a[1]) cout << 2 << endl;
    else {
        int sum = accumulate(a.begin(), a.end(), 0) - a.back();
        if (sum <= a.back()) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
