// http://codeforces.com/contest/544/problem/A
// A. Set of Strings
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    string in;
    cin >> n >> in;

    bool checked[26] = {false,};
    vector<string> out;

    string s(1, in[0]);
    checked[in[0] - 'a'] = true;
    for (int i = 1; i < in.length(); i++) {
        if (!checked[in[i] - 'a']) {
            checked[in[i] - 'a'] = true;
            out.push_back(s);
            s.clear();
        }
        s.append(1, in[i]);
    }
    out.push_back(s);

    if (out.size() >= n) {
        cout << "YES" << endl;
        int i;
        for (i = 0; i < n-1; i++) {
            cout << out[i] << endl;
        }
        for (; i < out.size(); i++) {
            cout << out[i];
        }
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
