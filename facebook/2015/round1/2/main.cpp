// https://www.facebook.com/hackercup/problems.php?pid=313229895540583&round=344496159068801
// Facebook Hacker Cup 2015 Round 1
// 2. Autocomplete
#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

string str[100 * 1000];
void solve() {
    set<string> s;
    int i, j, n;
    scanf("%d\n", &n);
    for (i = 0; i < n; i++) {
        cin >> str[i];
    }

    //sort(str, str + n);

    int c(0);
    for (i = 0; i < n; i++) {
        int size = str[i].size();
        for (j = 1; j <= size; j++) {
            if (s.find(str[i].substr(0, j)) == s.end()) {
                s.insert(str[i].substr(0, j));
                break;
            }
        }
        s.insert(str[i]);
        c += j;
    }

    printf("%d\n", c);
}

int main() {
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}

