#include <iostream>
#include <string>
#include <map>

using namespace std;

int f, n;
string s;
map<char, int> m;

int main() {
    cin >> n >> f >> s;
    for (char c : s) {
        m[c]++;
    }

    for (auto it : m) {
        if (f < it.second) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}

