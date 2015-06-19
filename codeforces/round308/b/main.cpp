// http://codeforces.com/contest/552/problem/B
// B. Vanya and Books
#include <iostream>

using namespace std;

int main() {
    long long n, c(9), prev(0), all(0);
    cin >> n;

    for (int i = 1; ; i++, prev = c, c = c*10+9) {
        if (c < n) {
            all += (c - prev) * i;
        }
        else {
            all += (n - prev) * i;
            break;
        }
    }
    cout << all << endl;
    return 0;
}
