// https://www.facebook.com/hackercup/problem/1153996538071503/
// Facebook Hacker Cup 2018 Qualification Round
// Ethan Searches for a String
#include <iostream>
#include <string>
#include <map>

using namespace std;

string s;
int len;
map<char, int> m;

bool contains(char c) {
    auto it = m.find(c);
    return it != m.end();
}

bool ok(int index, char c) { 
    int left = m[c];
    int right = index;

    left++; right++;
    while (left < index && right < len) {
        if (s[left] != s[right]) return true;
        left++; right++;
    }
    return false;
}

void solve(int no) {
    cout << "Case #" << no << ": ";
    len = s.size();
    if (len <= 2) goto FAIL;
    m[s[0]] = 0; m[s[1]] = 1;
    for (int i = 1; i < len; i++) {
        if (contains(s[i])) {
            if (ok(i, s[i])) {
                for (int j = 0; j < i; j++) cout << s[j];
                cout << s << endl;
                return;
            }
        } else {
            m[s[i]] = i;
        }
    }
FAIL:
    cout << "Impossible\n";
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> s;
        solve(i);
        m.clear();
    }
    return 0;
}
