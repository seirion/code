// https://www.hackerrank.com/contests/world-codesprint-7/challenges/similar-strings
// Similar Strings
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int n, q;
string in;

map<int, vector<int>> mm(int a, int b) {
    map<int, vector<int>> m;
    map<char, int> k; // key
    int num = 0;
    for (int i = a; i < b; i++) {
        char &c = in[i];

        if (k.find(c) != k.end()) {
            int key = k[c];
            m[key].push_back(i-a);
        }
        else {
            k[c] = num++;
        }
    }
    return m;
}

int solve(int a, int b) {
    int len = b - a;
    if (len == 1) return n;

    int limit = n - len + 1;
    long long r = 0;
    map<int, vector<int>> org = mm(a, b);

    for (int from = 0; from < limit; from++) {
        if (org == mm(from, from+len)) r++;
    }
    return r;
}

int main() {
    cin >> n >> q >> in;

    while (q--) {
        int a, b; cin >> a >> b;
        //solve(a-1, b);
        cout << solve(a-1, b) << endl; // [a-1, b) : 0-based
    }
    return 0;
}
