// codeforces round314
// http://codeforces.com/contest/567/problem/A
#include <iostream>

using namespace std;

int n;
int in[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    cout << in[1] - in[0] << " " << in[n-1] - in[0] << "\n";
    n--;
    for (int i = 1; i < n; i++) {
        cout << min(in[i+1] - in[i], in[i] - in[i-1]) << " " << max(in[n] - in[i], in[i] - in[0]) << "\n";
    }
    cout << in[n] - in[n-1] << " " << in[n] - in[0] << "\n";
    return 0;
}
