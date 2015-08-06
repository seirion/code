// codeforces round314
// http://codeforces.com/contest/567/problem/B
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main() {
    set<int> s;
    char c;
    int n, in, maxi = 0;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%c %d\n", &c, &in);
        if (c == '+') {
            s.insert(in);
            maxi = max(maxi, (int)s.size());
        }
        else { // '-'
            if (s.find(in) == s.end()) { // not found
                maxi++;
            } 
            else { // found
                s.erase(in);
            }
        }
    }
    printf("%d\n", maxi);
    return 0;
}
