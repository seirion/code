#include <iostream>

using namespace std;


void solve() {
    int index;
    cin >> index;

    char buffer[80];
    cin >> buffer;

    buffer[index-1] = '\0';

    static int num = 1;
    cout << num++ << " " << buffer << buffer + index << endl;
}

int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        solve();
    }
    return 0;
}
