//
#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long in[100000];

int main() {
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        sum += in[i];
    }

    while (sum & 1) {
        sort(in, in+n);
        int i;
        for (i = 0; i < n; i++) {
            if (in[i] & 1) break;
        }
        sum -= in[i];
    }
    cout << sum << endl;
    return 0;
}
