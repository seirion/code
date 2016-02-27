//
#include <iostream>

using namespace std;

int n;
bool in[1001][1001] = { false, };

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int r, c; cin >> r >> c;
        in[r][c] = true;
    }

    long long out = 0;
    for (int col = 2; col <= 1000; col++) { // /
        int r = 1;
        int c = col;

        int num = 0;
        while (r <= 1000 && 1 <= c) {
            if (in[r][c]) num++;
            r++;
            c--;
        }
        out += num * (num-1) / 2;
    }

    for (int row = 2; row < 1000; row++) { // /
        int r = row;
        int c = 1000;
        int num = 0;
        while (r <= 1000 && 1 <= c) {
            if (in[r][c]) num++;
            r++;
            c--;
        }
        out += num * (num-1) / 2;
    }


    for (int row = 1000-1; 1 <= row; row--) { // 
        int r = row;
        int c = 1;
        int num = 0;
        while (r <= 1000 && c <= 1000) {
            if (in[r][c]) num++;
            r++;
            c++;
        }
        out += num * (num-1) / 2;
    }

    for (int col = 2; col < 1000; col++) {
        int r = 1;
        int c = col;
        int num = 0;
        while (r <= 1000 && c <= 1000) {
            if (in[r][c]) num++;
            r++;
            c++;
        }
        out += num * (num-1) / 2;
    }
    cout << out << endl;
    return 0;
}
