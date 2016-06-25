// 짝수 단어
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string str;
int size;

void input() {
    cin >> str;
    size = str.size();
    for (char &c : str) c -= 'a';
}

void solve() {
    long long r = 0;
    for (int from = 0; from < size; from++) {
        int ok = 0;
        for (int to = from+1; to < size; to+=2) {
            ok ^= 1 << str[to-1];
            ok ^= 1 << str[to];
            if (ok == 0) r++;
        }
    }
    cout << r << endl;
}

int main() {
    int t; cin >> t;
    while (t--) { input(); solve(); }
    return 0;
}
