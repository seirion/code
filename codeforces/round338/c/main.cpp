// http://codeforces.com/contest/615/problem/C
// C. Running Track
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string s1, s2;
map<string, pair<int, int> > m;

void build(int begin) {
    int max_len = s1.size() - begin;
    for (int i = 1; i <= max_len; i++) {
        string sub = s1.substr(begin, i);
        m[sub] = make_pair(begin, begin+i-1);

        reverse(sub.begin(), sub.end());
        m[sub] = make_pair(begin+i-1, begin);
    }
}

int main() {
    cin >> s1 >> s2;

    int size = s1.size();
    for (int i = 0; i < size; i++) {
        build(i);
    }

    int now = 0;

    vector<pair<int, int> > result;
    while (now < s2.size()) {
        int len = min(s2.size() - now, s1.size());

        while (len >= 1) {
            string sub = s2.substr(now, len);

            auto it = m.find(sub);
            if (it != m.end()) { // found
                result.push_back(make_pair(it->second.first, it->second.second));
                now += len;
                break;
            }
            else {
                len--;
            }
        }

        if (len == 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << result.size() << endl;
    for (auto x : result) {
        cout << x.first+1 << " " << x.second+1 << endl;
    }
    return 0;
}
