// http://algospot.com/judge/problem/read/MEETING
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int m[10000];
int w[10000];

void getInput() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> m[i];
    for (int i = 0; i < n; i++) cin >> w[i];
}

void solve() {
    sort(m, m+n);
    sort(w, w+n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(m[i] - w[i]);
    }

    cout << sum << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
