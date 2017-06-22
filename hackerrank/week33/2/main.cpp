#include <iostream>
#include <string>

using namespace std;

enum {ONE, ZERO, NO};

int num(const string &s) {
    int r = 0;
    char prev = 'x';
    int state = NO;
    for (char c : s) {
        switch (c) {
            case '1':
                if (state == ZERO) r++;
                state = ONE;
                break;
            case '0':
                if (state == ONE) state = ZERO;
                break;
            default:
                state = NO;
                break;
        }
        prev = c;
    }
    return r;
}

int main() {
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        cout << num(s) << endl;
    }
    return 0;
}
