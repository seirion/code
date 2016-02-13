// https://www.hackerrank.com/challenges/acm-icpc-team
// ACM ICPC Team
#include <iostream>

using namespace std;

typedef unsigned int uint32;

int n, m;
uint32 bit[500][20] = {0, }; // 32 * 20 = 640 > 500

int count_bit(int a, int b) {
    int cc = 0;
    const int size = (m + 31) / 32;
    for (int i = 0; i < size; i++) {
        cc += __builtin_popcount(bit[a][i] | bit[b][i]);
    }
    return cc;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) { // convert to bit flags
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '1') {
                bit[i][j/32] |= (1 << (j%32));
            }
        }
    }

    int cc = 0;
    int maxi = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int temp = count_bit(i, j);
            if (temp > maxi) {
                cc = 1;
                maxi = temp;
            }
            else if (temp == maxi) {
                cc++;
            }
        }
    }

    cout << maxi << endl << cc << endl;
    return 0;
}

