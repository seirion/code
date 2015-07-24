// codeforces round313
// http://codeforces.com/contest/560/problem/D
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string sort_of(string s) {
    int size = s.size();
    if (size & 1) return s;

    string a[2];
    a[0] = sort_of(s.substr(0, size>>1));
    a[1] = sort_of(s.substr(size>>1, size));
    sort(a, a+2);
    return a[0] + a[1];
}

int main() {
    string a, b;
    cin >> a >> b;
    if (sort_of(a) == sort_of(b)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
