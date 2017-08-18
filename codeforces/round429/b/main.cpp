#include <iostream>
#include <cstdio>

using namespace std;

int n;

int main() {
    cin >> n;
    while (n--) {
        int x;// cin >> x;
        scanf("%d", &x);
        if (x % 2 == 1) {
            cout << "First\n";
            return 0;
        }
    }

    cout << "Second\n";
    return 0;
}
