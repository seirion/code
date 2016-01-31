// World CodeSprint
// Flatland Space Stations
// https://www.hackerrank.com/contests/worldcodesprint/challenges/powerplants-in-flatland
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
bool in[100001] = { false, };

int main() {
    cin >> n >> m;
    vector<int> in(m);
    for (int i = 0; i < m; i++) {
        cin >> in[i];
    }

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    sort(in.begin(), in.end());

    int maxi = in[0];
    for (int i = 1; i < m; i++) {
        maxi = max(maxi, (in[i] - in[i-1]) / 2);
    }
    maxi = max(maxi, n - 1 - in[m-1]);
    cout << maxi << endl;
    return 0;
}
