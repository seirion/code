// http://codeforces.com/contest/546/problem/A
// A. Soldier and Bananas
#include <iostream>

using namespace std;

int main() {
    int price, mine, num;
    cin >> price >> mine >> num;
    int sum = price * (num * (num+1) / 2);
    int borrow = max(0, sum - mine);
    cout << borrow << endl;
    return 0;
}
