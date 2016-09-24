#include <iostream>

using namespace std;

int n;
int in[100];

int main() {
    cin >> n;

    int a, b;
    for (int i = 0; i < n-1; i++) cin >> a;

    if (n == 1) {
        cin >> a;
        if (a == 0) cout << "UP\n";
        else if (a == 15) cout << "DOWN\n";
        else cout << "-1\n";
        return 0;
    }

    cin >> b;

    if (b == 0) cout << "UP\n";
    else if (b == 15) cout << "DOWN\n";
    else {
        if (a < b) cout << "UP\n";
        else cout << "DOWN\n";
    }

    return 0;

}
