#include <iostream>


using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    int r = 0;
    for (int i = 1; i <= n; i++) {
        if (i % a == 0 && i % b == 0) r++;
    }
    cout << r << endl;
    return 0;
}

