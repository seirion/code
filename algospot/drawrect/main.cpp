#include <iostream>

using namespace std;


int getOnly(int *array) {
    if (array[0] == array[1]) return array[2];
    if (array[0] == array[2]) return array[1];
    return array[0];
}

void solve() {
    int xs[3] = {0,};
    int ys[3] = {0,};

    for (int i = 0; i < 3; i++) {
        cin >> xs[i];
        cin >> ys[i];
    }

    cout << getOnly(xs) << " ";
    cout << getOnly(ys) << endl;
}

int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        solve();
    }
    return 0;
}
