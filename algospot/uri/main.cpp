#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

const char CODE[] = {
    ' ',
    '!',
    'x',
    'x',
    '$',
    '%',
    'x',
    'x',
    '(',
    ')',
    '*', // a
};

void solve() {
    char buffer[128];
    cin >> buffer;

    size_t size = strlen(buffer);
    for (int i = 0; i < size; i++) {
        if (buffer[i] == '%' && buffer[i+1] == '2') {
            if (buffer[i+2] == 'a') {
                cout << '*'; 
            }
            else {
                cout << CODE[buffer[i+2] - '0'];
            }
            i += 2;
        }
        else {
            cout << buffer[i];
        }
    }
    cout << endl;
}

int main() {
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        solve();
    }
    return 0;
}
