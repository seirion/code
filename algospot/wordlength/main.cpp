// http://algospot.com/judge/problem/read/WORDLENGTH
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n;


void processing(char *buffer, size_t size, int &length, int &count) {
}

void getInput() {
    enum {READY, ING, CONTINUE};

    cin >> n;
    cin.get();
    char buffer[81];

    int length(0), count(0);
    int state = READY;
    for (int i = 0; i < n; i++) {
        gets(buffer);
        size_t size = strlen(buffer);
        for (int j = 0; j < size; j++) {
            char ch = buffer[j];
            switch (state) {
            case READY:
                if (ch >= 'a') {
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

    length = (length * 10000 + 5 ) / count;
    printf("%d.%04d\n", length / 10000, length % 10000);
}

void solve() {


}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
