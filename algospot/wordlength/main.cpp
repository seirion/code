// http://algospot.com/judge/problem/read/WORDLENGTH
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int n;

void solve() {
    enum {READY, ING, CONTINUE};

    cin >> n;
    cin.get();
    char buffer[1000];

    int length(0), count(0);
    int state = READY;
    for (int i = 0; i < n; i++) {
        gets(buffer);
        size_t size = strlen(buffer);
        if (size == 0) state = READY;
        for (int j = 0; j < size; j++) {
            char ch = buffer[j];
            switch (state) {
            case READY:
                if ('a' <= ch && ch <= 'z') {
                    length++; count++;
                    state = ING;
                }
                break;
            case ING:
                if (ch == ' ') {
                    state = READY;
                }
                else if (ch == '-') {
                    if (j + 1 == size) { // end of line
                        state = CONTINUE;
                    }
                    else state = READY;
                }
                else {
                    length++;
                }
                break;
            case CONTINUE:
                if (ch == ' ') {
                    state = READY;
                }
                else if (ch == '-') {
                    if (j + 1 != size) {
                        state = READY;
                    }
                }
                else { // 'a' ~
                    length++;
                    state = ING;
                }
                break;
            default: break;
            }
        }
        if (state != CONTINUE) state = READY;
    }

    length = ((length * 10000) / count + 5) / 10;
    printf("%d.%03d\n", length / 1000, length % 1000);
    //printf("%.03f\n", floor((length / (double)count + 0.0005) * 1000) / 1000);
}


int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {solve();}
    return 0;
}
