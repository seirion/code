// http://codeforces.com/contest/527/problem/B
// B. Error Correct System

#include <cstdio>
#include <map>

using namespace std;

int n;
char in1[200 * 1000 + 1];
char in2[200 * 1000 + 1];

map<char, map<char, int> > mm;

void solve() {
    int distance = 0;
    for (int i = 0; i < n; i++) {
        if (in1[i] == in2[i]) continue;

        mm[in1[i]][in2[i]] = i;
        distance++;
    }

    int found(0), index1(-1), index2(-1);
    for (auto i : mm) {
        char ch1 = i.first;
        auto m = i.second;
        for (auto j : m) {
            char ch2 = j.first;
            int index = j.second;

            if (mm.find(ch2) != mm.end()) {
                if (mm[ch2].find(ch1) != mm[ch2].end()) {
                    printf("%d\n%d %d\n", distance - 2, index + 1, mm[ch2][ch1] + 1);
                    return;
                }
                found = 1;
                index1 = index + 1; index2 = mm[ch2].begin()->second + 1;
            }
        }
    }
    printf("%d\n%d %d\n", distance - found, index1, index2);
}

int main() {
    scanf("%d\n", &n);
    gets(in1);
    gets(in2);
    solve();
    return 0;
}
