// http://algospot.com/judge/problem/read/KTHDICTNUM
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <iostream>

using namespace std;

typedef unsigned long long uint64;

uint64 from, to, k;


void solve() {
    scanf("%lld %lld %lld", &from, &to, &k);

    char buffer[20];
    set<string> s;
    for (int i = from; i <= to; i++) {
        sprintf(buffer, "%d", i);
        s.insert(buffer);
    }
    set<string>::const_iterator it = s.begin();
    advance(it, k);
    printf("%s\n", it->c_str()); // [from, to)
}

int main() {
    printf("%lld\n", (unsigned long long)(1ll << 63) - 1);
    return 0;
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) { solve(); }
    return 0;
}
