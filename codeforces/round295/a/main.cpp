// http://codeforces.com/contest/520/problem/A
// A. Pangram
#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int length;
    cin >> length;
    string str;
    cin >> str;

    transform(str.begin(), str.end(), str.begin(), ::tolower);
    set<char> alphabet;
    for (auto c : str) {
        alphabet.insert(c);
    }
    if (alphabet.size() == 26) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
