#include <iostream>
#include <string>

using namespace std;

int n, t;
string s;

int main() {
    cin >> n >> t >> s;

    int i, p;
    for (i = 0; i < n; i++) if (s[i] == '.') break;
    p = i++;

    for (; i < n; i++) if ('5' <= s[i]) break;

    if (i == n) {
        cout << s << endl;
        return 0;
    }

    // +
    i--;
    bool stop = false;

BEGIN:
    for (; 0 <= i; i--) {
        if (s[i] == '.') {
            stop = true;
        }
        else if (s[i] == '9') {
            if (stop) s[i] = '0';
        }
        else {
            s[i]++;
            break;
        }
    }

    t--;
    if (!stop && t && 0 <= i && '5' <= s[i]) {
        i--;
        goto BEGIN;
    }

OUT:
    if (stop) s = s.substr(0, p);
    else s = s.substr(0, i+1);

    if (i == -1) {
        cout << 1;
    }
    cout << s << endl;

    return 0;
}
