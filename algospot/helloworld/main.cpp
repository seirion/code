#include <iostream>

using namespace std;

char b[64];

int main() {
    int n;
    cin >> n;
    cin.getline(b, 64);
    for (int i = 0; i < n; i++) {
        cin.getline(b, 64);
        cout << "Hello, " << b << "!" << endl;
    }
    return 0;
}
