#include <iostream>

using namespace std;

int n;
int in[200000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];

    int limit = n / 2;
    for (int i = 0; i < limit; i++) {
        if (i % 2 == 0) {
            int temp = in[i];
            in[i] = in[n - i - 1];
            in[n - i - 1] = temp;
        }
    }
    for (int i = 0; i < n; i++) cout << in[i] << " ";
    cout << endl;
    return 0;
}
