#include <iostream>
#include <algorithm>

using namespace std;

int n, hit, t;
int in[100000];

int main() {
    cin >> n >> hit >> t;
    for (int i = 0; i < n; i++) cin >> in[i];
    sort(in, in+n);

    int i;
    for (i = 0; i < n; i++) {
        int temp = (in[i] + hit - 1) / hit;
        if (t < temp) break;
        t -= temp;
    }
    cout << i << endl;
    return 0;
}
