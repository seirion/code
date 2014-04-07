// http://algospot.com/judge/problem/read/TRIANGLEPATH
#include <iostream>
#include <cstring>

using namespace std;

int n;
int in[101][101];
int temp[101][101];


void getInput() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> in[i][j];
        }
    }
}

void solve() {
    memset(temp, 0, sizeof(int) * 101 * 101);
    temp[1][1] = in[1][1];
    int i;
    for (i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            temp[i][j] = max(temp[i-1][j-1], temp[i-1][j]) + in[i][j];
        }
    }

    int maxi = 0;
    for (i = 1; i <= n; i++) {
        maxi = max(maxi, temp[n][i]);
    }

    cout << maxi << endl;
}

int main() {
    memset(in, 0, sizeof(int) * 101 * 101);
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
