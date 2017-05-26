#include <iostream>

using namespace std;

int main() {
    int n, t; cin >> n;
    int sum1(0), sum2(0);
    t = n / 2;
    while (t--) {
        int x; cin >> x;
        sum1 += x;
    }

    t = n / 2;
    while (t--) {
        int x; cin >> x;
        sum2 += x;
    }

    cout << abs(sum1-sum2) << endl;
    return 0;
}
