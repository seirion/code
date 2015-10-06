// https://www.lgcodechallenger.com
// problem 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int64;

const int64 MAXN = 10000000;

vector<int64> square;
int ccc[MAXN+1] = {0, };

bool is_square_of_n(int64 x) { // binary search
    auto i = lower_bound(square.begin(), square.end(), x);
    return (i != square.end() && *i == x);
}

void init() {
    square.push_back(1);
    for (int64 i = 1; i <= MAXN; i++) {
        square.push_back(i*i);
    }
    //cout << square.size() << endl;

    for (int64 a = 1; a*a*a <= MAXN; a++) {
        for (int64 b = a; a*b*b <= MAXN; b++) {
            for (int64 c = b; a*b*c <= MAXN; c++) {
                if (is_square_of_n(a*a + b*b + c*c)) ccc[a*b*c]++;
            }
        }
    }

    for (int i = 1; i <= MAXN; i++) {
        ccc[i] += ccc[i-1];
    }
}

void solve() {
    int n; cin >> n;
    cout << ccc[n] << endl;
}

int main() {
    init();
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
