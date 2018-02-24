// http://algospot.com/judge/problem/read/UNORDSEQ
#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int n;
int in[100000];
multiset<int> s;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        s.insert(in[i]);
    }
    s.erase(s.find(in[0])); // remove first one
}

bool go_up() {
}

void solve() {
    int a(0), b, c(-1);

    for (b = 1; b < n; b++) {
        s.erase(s.find(in[b]));
        if (in[a] == in[b]) continue;

        if (in[a] < in[b]) { // +
            auto it = s.lower_bound(in[b]);
            if (it != s.begin()) {
                int x = *it;
                while (in[b] <= x && it != s.begin()) {
                    x = *--it;
                }
                if (x < in[b]) {
                    for (c = b+1; c < n; c++) {
                        if (in[c] < in[b]) {
                            goto OUT;
                        }
                    }
                }
            }
        }
        else {
            auto it = s.upper_bound(in[b]);
            if (it != s.end()) {
                for (c = b+1; c < n; c++) {
                    if (in[b] < in[c]) {
                        goto OUT;
                    }
                }
            }
        }
    }

OUT:
    if (c == -1) {
        printf("0\n");
    } else {
        printf("3\n%d %d %d\n", a+1, b+1, c+1);
    }
    s.clear(); // reset
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {input(); solve();}
    return 0;
}
