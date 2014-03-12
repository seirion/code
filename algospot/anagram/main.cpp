// http://algospot.com/judge/problem/read/ANAGRAM
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int n;
char serial[101];
char pass[101];


void getInput() {
    scanf("%s %s", serial, pass);
}

void solve() {
    if (strcmp(serial, pass) == 0) {
        cout << "No." << endl;
    }
    else {
        sort(serial, serial + strlen(serial));
        sort(pass, pass + strlen(pass));
        if (strcmp(serial, pass) == 0) {
            cout << "Yes" << endl;
        }
        else cout << "No." << endl;
    }
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
