#include <iostream>
#include <string>

using namespace std;

string s;
int k;


int check() {
    if (s.size() == 1 && s[0] == '0') return 0;
    if (s.size() < k) return s.size() - 1;

    int cc = 0;
    int r = 0; // removed
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0') {
            cc++;
            if (k == cc) return r;
        } else {
            r++;
        }
    }
    return s.size() - 1;
}

int main() {
    cin >> s >> k;
    cout << check() << endl;
    return 0;
}

