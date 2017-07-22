#include <iostream>

using namespace std;

int sum(int x) {
    int r = 0;
    while (x) {
        r += x % 10;
        x = x / 10;
    }
    return r;
}

bool lucky(int n) {
    return sum(n / 1000) == sum(n % 1000);
}

int main() {
    int n; cin >> n;

    while (true) {
        n++;
        if (lucky(n)) {
            cout << n << endl;
            break;
        }
    }
    return 0;
}
