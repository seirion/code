// http://codeforces.com/contest/538/problem/B
// B. Quasi Binary
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    const int SIZE = 7; // input <= 10e6
    int in;
    cin >> in;

    int container [SIZE] = {0, };
    int i(0);
    while (in) {
        container[i++] = in % 10;
        in = in / 10;
    }
    
    int max_num = *max_element(container, container+SIZE);
    cout << max_num << endl;
    vector<int> out;
    for (int i = 0; i < max_num; i++) {
        int r(0);
        for (int j = SIZE-1; j >= 0; j--) {
            r = r * 10;
            if (container[j] > 0) {
                container[j]--;
                r++;
            }
        }
        out.push_back(r);
    }

    for (auto i : out) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
