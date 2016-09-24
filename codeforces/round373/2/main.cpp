#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int n;
string in;

int main() {
    cin >> n;
    cin >> in;

    int i, r(0), b(0), size(in.size());
    char now = 'r';

    for (i = 0; i < size; i++) {
        if (now != in[i]) {
            if (in[i] == 'r') r++;
            else b++;
        }
        now = now == 'r' ? 'b' : 'r';
    }

    int result = max(r, b);

    now = 'b';
    r = b = 0;
    for (i = 0; i < size; i++) {
        if (now != in[i]) {
            if (in[i] == 'r') r++;
            else b++;
        }
        now = now == 'r' ? 'b' : 'r';
    }

    cout << min(result, max(r, b)) << endl;
    return 0;
}
