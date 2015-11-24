// https://www.hackerrank.com/contests/w18/challenges/target
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, n;
vector<long long> circle;

int main() {
    cin >> k >> n;

    circle.resize(k);
    int sum = 0;
    for (int i = k-1; i >= 0; i--) {
        cin >> circle[i];
        circle[i] = circle[i] * circle[i];
    }

    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        auto it = lower_bound(circle.begin(), circle.end(), x*x+y*y);
        if (it != circle.end()) {
            sum += (k - (it-circle.begin()));
        }
    }

    cout << sum << endl;
    return 0;
}
