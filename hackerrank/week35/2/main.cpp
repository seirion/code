#include <iostream>

using namespace std;

int n, m, k;

int in[101][101] = {0, };

int main() {
    cin >> n >> m >> k;

    in[0][0] = m;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (r == 0 && c == 0) continue;

            if (r == c) {
                in[r][c] = in[r-1][c-1] + k;
            } else if (r > c) {
                in[r][c] = in[r-1][c] - 1;
            } else {
                in[r][c] = in[r][c-1] - 1;
            }
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cout << in[r][c] << " ";
        }
        cout << endl;
    }
    return 0;
}
