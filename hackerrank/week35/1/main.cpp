#include <iostream>

using namespace std;

bool ok(int n) {
    int f(0), s(0);
    while (n) {
        int nn = n % 10;
        if (nn == 4) f++;
        else if (nn == 7) s++;
        else return false;

        n /= 10;
    }
    return 0 < f && f == s;
}

int main() {
    int n; cin >> n;
    int best = 0x7fffffff;
    string ss;

    while (n--) {
        int nn; string s;
        cin >> s >> nn;
        if (ok(nn) && nn < best) {
            best = nn;
            ss = s;
        }
    }

    if (ss.empty()) cout << "-1\n";
    else cout << ss << endl;
    return 0;
}
