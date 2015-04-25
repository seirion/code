// http://codeforces.com/contest/535/problem/B
// B. Tavas and SaDDas
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef unsigned int uint32;

int main() {
    char buffer[12];
    fgets(buffer, 12, stdin);

    int i(0), c(1);
    int len = strlen(buffer) - 1;
    for (int i = 0; i < len; i++) {
        c = c << 1;
        if (buffer[i] == '7') {
            c |= 1;
        }
    }
    cout << c - 1<< endl;
    return 0;
}
