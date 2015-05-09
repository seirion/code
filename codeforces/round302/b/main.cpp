// http://codeforces.com/contest/544/problem/B
// B. Sea and Islands
#include <iostream>
#include <cstring>

using namespace std;

char world[100][100];

int main() {
    int size, n;
    cin >> size >> n;

    for (int i = 0; i < size; i++) {
        memset(world[i], 'S', sizeof(char) * 100);
    }

    int c = 0;
    if (n == 0) goto OUT;

    for (int i = 0; i < size; i++) {
        int j = i % 2;
        for (; j < size; j+= 2) {
            world[i][j] = 'L';
            if (++c == n) goto OUT;
        }
    }

OUT:
    if (c == n) {
        cout << "YES" << endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << world[i][j];
            }
            cout << endl;
        }
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
