#include <iostream>
#include <string>

using namespace std;

const int days [] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const char* week [] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
int v[12];

int w(const string &s) {
    for (int i = 0; i < 7; i++) {
        if (s == week[i]) return i;
    }
    return 0;
}

int main() {
    string sa, sb;
    cin >> sa >> sb;

    int a = w(sa);
    int b = w(sb);
    if (a == b) goto OK;

    v[0] = days[0];
    for (int i = 1; i < 12; i++) v[i] = (v[i-1] + days[i]) % 7;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 11; j++) if (v[j] == a && v[j+1] == b) goto OK;
    }

    for (int i = 1; i < 7; i++) {
        for (int k = 0; k < 12; k++) v[k] = (v[k] + 1) % 7;
        for (int j = 0; j < 11; j++) if (v[j] == a && v[j+1] == b) goto OK;
    }

NO:
    cout << "NO\n";
    return 0;
OK:
    cout << "YES\n";
    return 0;
}
