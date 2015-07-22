// codeforces round313
// http://codeforces.com/contest/560/problem/D
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

char a[200002];
char b[200002];

int size;

bool com(int i, int j, int s) {
    if (strncmp(a+i, b+j, s) == 0) return true;
    if (s & 1) return false;
    s >>= 1;

    return (com(i, j, s) && com(i+s, j+s, s)) ||
    (com(i, j+s, s) && com(i+s, j, s));
}

int main() {
    fgets(a, 200002, stdin);
    fgets(b, 200002, stdin);

    bool r = com(0, 0, strlen(a) - 1);
    if (r) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
