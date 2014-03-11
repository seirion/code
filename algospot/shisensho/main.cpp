#include <iostream>

using namespace std;


void solve() {
    int input;
    cin >> input;

    vector<int> divisors = getDivisors(input);
    print(exceed(divisors, input) && !hasExactSum(divisors, input));
}

int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        solve();
    }

    return 0;
}
