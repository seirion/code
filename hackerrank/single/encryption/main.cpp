// https://www.hackerrank.com/challenges/encryption
// Encryption
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char in [100] = {0, };

int main() {
    fgets(in, 100, stdin);

    int size = strlen(in);
    while (true) {
        char &ch = in[size-1];
        if (ch < 'a' || 'z' < ch) size--;
        else break;
    }

    int col = 1;
    while (col * col < size) col++;
    int row = (size+col-1) / col;

    int c = 0;
    while (0 < size) {
        for (int r = 0; r < row; r++) {
            char &ch = in[r*col+c];
            if ('a' <= ch && ch <= 'z') {
                cout << in[r*col+c];
                size--;
            }
        }
        cout << ' ';
        c++;
    }
    cout << endl;

    return 0;
}
