// http://algospot.com/judge/problem/read/PCOMPLETE
#include <cstdio>
#include <iostream>

using namespace std;

int size, p, q;
char in[1001];
void input() {
    scanf("%d\n", &size);
    gets(in);
    scanf("%d %d\n", &p, &q);
}

void solve() {
    int s(0), e(size-1), cost(0);
    const int min_value = min(p, q);
    while (s < e) {
        if (in[s] == '?' && in[e] == '?') {
            cost += min_value * 2;
        }
        else if (in[s] == '?') {
            cost += in[e] == 'a' ? p : q;
        }
        else if (in[e] == '?') {
            cost += in[s] == 'a' ? p : q;
        }
        s++;
        e--;
    }
    if (s == e && in[s] == '?') {
        cost += min_value;
    }
    printf("%d\n", cost);
}

int main() {
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; i++) { input(); solve(); }
    return 0;
}
