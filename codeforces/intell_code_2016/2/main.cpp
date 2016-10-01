#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int n;
int in[100];

bool ok(char *buffer, int x) {
    int size = strlen(buffer);

    int r = 0;
    for (int i = 0; i < size; i++) {
        char &c = buffer[i];
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'y':
                r++;
                break;
            default:
                break;
        }
    }

    return r == x;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> in[i];

    char buffer[128];
    gets(buffer);

    for (int i = 0; i < n; i++) {
        gets(buffer);
        if (!ok(buffer, in[i])) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
