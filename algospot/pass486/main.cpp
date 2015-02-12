// https://algospot.com/judge/problem/read/PASS486
#include <cstdio>

using namespace std;

const int LIMIT = 10000000;
int nprime[LIMIT + 1] = {0,};


void make_table() {
    for (int i = 2; i <= LIMIT; i++) {
        for (int j = i; j <= LIMIT; j+= i) {
            nprime[j]++;
        }
    }
}

void solve() {
    int n, from, to;
    scanf("%d %d %d", &n, &from, &to);
    int c(0); n--;
    for (int i = from; i <= to; i++) {
        if (nprime[i] == n) c++;
    }
	printf("%d\n", c);
}

int main() {
    make_table();
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        solve();
    }
    return 0;
}

