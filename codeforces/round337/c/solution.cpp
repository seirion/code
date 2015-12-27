// http://codeforces.com/contest/610/problem/C
#include <iostream>
#include <vector>

using namespace std;
int n;

void print(const vector<char> &v) {
    for (const char &c : v) {
        cout << c;
    }
    cout << endl;
}

void rec(vector<char> v, int x) {
    if (x == n) {
        print(v);
        return;
    }

    int limit = v.size();
    for (int i = 0; i < limit; i++) {
        v.push_back(v[i]);
    }
    rec(v, x+1);

    for (int i = limit; i < v.size(); i++) {
        if (v[i] == '+') v[i] = '*';
        else v[i] = '+';
    }
    rec(v, x+1);
}

int main() {
    n; cin >> n;
    vector<char> v;
    v.push_back('+');

    rec(v, 0);
    return 0;
}
