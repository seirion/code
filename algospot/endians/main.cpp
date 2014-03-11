#include <iostream>

using namespace std;


unsigned int swap(unsigned int in) {
    unsigned int out = 0;
    out = (in & 0xFF000000) >> 24;
    out |= (in & 0x00FF0000) >> 8;
    out |= (in & 0x0000FF00) << 8;
    out |= (in & 0x000000FF) << 24;

    return out;
}

void solve() {
    unsigned int input;
    cin >> input;

    cout << swap(input) << endl;
}

int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        solve();
    }
    return 0;
}
