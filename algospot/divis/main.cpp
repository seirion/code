// http://algospot.com/judge/problem/read/DIVIS
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n;
char in[10001];
char dict[123];

void solve() {
    int size = strlen(in);
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += dict[in[i]];
    }
    if (total % 61 == 0) cout << "yes" << endl;
    else cout << "no" << endl;
}

int main() {
    int i, v(0);
    for (i = '0'; i <= '9'; i++) {
        dict[i] = v++;
    }
    for (i = 'A'; i <= 'Z'; i++) {
        dict[i] = v++;
    }
    for (i = 'a'; i <= 'z'; i++) {
        dict[i] = v++;
    }
    while (true) {
        gets(in);
        if (strcmp(in, "end") == 0) {
            break;
        }
        else {
            solve();
        }
    }
    return 0;
}
