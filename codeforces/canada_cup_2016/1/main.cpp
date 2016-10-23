#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; string s;
    cin >> n >> s;
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '>') break;
        else r++;
    }
    for (int i = n-1; 0 <= i; i--) {
        if (s[i] == '<') break;
        else r++;
    }
    cout << r << endl;
    return 0;
}

