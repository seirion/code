// http://algospot.com/judge/problem/read/TRIPATHCNT
#include <iostream>
#include <cstring>

using namespace std;

int n;
int in[101][101];
int maxv[101][101];
int pathnum[101][101];


void getInput() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> in[i][j];
        }
    }
}

void solve() {
    memset(maxv, 0, sizeof(int) * 101 * 101);
    memset(pathnum, 0, sizeof(int) * 101 * 101);
    maxv[1][1] = in[1][1];
    pathnum[1][1] = 1;
    int i;
    for (i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            maxv[i][j] = maxv[i-1][j-1] + in[i][j];
            pathnum[i][j] = pathnum[i-1][j-1];
            if (maxv[i][j] == maxv[i-1][j] + in[i][j]) {
                pathnum[i][j] += pathnum[i-1][j];
            }
            else if (maxv[i][j] < maxv[i-1][j] + in[i][j]) {
                maxv[i][j] = maxv[i-1][j] + in[i][j];
                pathnum[i][j] = pathnum[i-1][j];
            }
        }
    }

    int maxi = 0;
    for (i = 1; i <= n; i++) {
        maxi = max(maxi, maxv[n][i]);
    }
    int maxpathnum = 0;
    for (i = 1; i <= n; i++) {
        if (maxv[n][i] == maxi) maxpathnum += pathnum[n][i];
    }

    cout << maxpathnum << endl;
}

int main() {
    memset(in, 0, sizeof(int) * 101 * 101);
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
