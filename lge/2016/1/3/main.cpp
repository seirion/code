// 짝수 단어
#include <iostream>
#include <string>
#include <map>

using namespace std;

string str;
int size;
int xors[50001];

void input() {
    cin >> str;
    size = str.size();
}

void solve() {
    xors[0] = 1 << (str[0] - 'a');
    for (int i = 1; i < size; i++) xors[i] = xors[i-1] ^ (1 << (str[i]-'a'));

    map<int, int> m;
    m[0]++;
    for (int i = 0; i < size; i++) m[xors[i]]++;

    long long r = 0;
    for (const auto &it : m) {
        const int &c = it.second;
        if (it.first == 0 && c == 0) r++;
        else if (2 <= c) {
            r += c * (c - 1) / 2;
        }
    }
    cout << r << endl;
}

int main() {
    int t; cin >> t;
    while (t--) { input(); solve(); }
    return 0;
}
