// https://code.google.com/codejam/contest/dashboard?c=11254486#s=p1
// Problem B. Close Match
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string a, b;
string best, best1, best2; // small diff
int size;

string diffv(const string &s1, const string &s2) { // s1 < s2
    string out;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] <= s2[i]) {
            out.push_back(s2[i] - s1[i] + '0');
        }
        else {
            out.push_back(10 + s2[i] - s1[i] + '0');
            out[i-1]--;
        }
    }
    return out;
}

void find(int i, int diff, string out1, string out2) {
    if (i == size) {
        string temp;
        if (out1 <= out2) temp = diffv(out1, out2);
        else temp = diffv(out2, out1);
        if (temp < best || (temp == best && (out1 < best1 || out2 < best2))) {
            best = temp;
            best1 = out1;
            best2 = out2;
        }
        return;
    }

    if (diff == 0) {
        if (a[i] == '?' && b[i] == '?') {
            out1.push_back('0');
            out2.push_back('0');
            find(i+1, diff, out1, out2);

            out1[i] = '1';
            find(i+1, 1, out1, out2);

            out1[i] = '0';
            out2[i] = '1';
            find(i+1, -1, out1, out2);
        }
        else if (a[i] == '?') {
            out1.push_back(b[i]);
            out2.push_back(b[i]);
            find(i+1, diff, out1, out2); // a == b

            if (b[i] != '0') {
                out1[i] = b[i] - 1;
                find(i+1, -1, out1, out2); // a < b
            }

            if (b[i] != '9') {
                out1[i] = b[i] + 1;
                find(i+1, 1, out1, out2); // b < a
            }
        }
        else if (b[i] == '?') {
            out1.push_back(a[i]);
            out2.push_back(a[i]);
            find(i+1, diff, out1, out2); // a == b

            if (a[i] != '9') {
                out2[i] = a[i] + 1;
                find(i+1, -1, out1, out2); // a < b
            }

            if (a[i] != '0') {
                out2[i] = a[i] - 1;
                find(i+1, 1, out1, out2); // b < a
            }
        }
        else {
            out1.push_back(a[i]);
            out2.push_back(b[i]);
            find(i+1, a[i] - b[i], out1, out2);
        }
        return;
    }

    if (a[i] == '?' && b[i] == '?') {
        if (diff < 0) { // a < b
            out1.push_back('9');
            out2.push_back('0');
        }
        else {
            out1.push_back('0');
            out2.push_back('9');
        }
    }
    else if (a[i] == '?') {
        if (diff < 0 ) out1.push_back('9');
        else out1.push_back('0');
        out2.push_back(b[i]);
    }
    else if (b[i] == '?') {
        out1.push_back(a[i]);
        if (diff < 0) out2.push_back('0');
        else out2.push_back('9');
    }
    else {
        out1.push_back(a[i]);
        out2.push_back(b[i]);
    }
    find(i+1, diff, out1, out2);
}

void solve() {
    cin >> a >> b;
    size = a.size();

    string temp(size, '9');
    best.swap(temp);
    find(0, 0, "", "");
    cout << best1 << " " << best2 << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}

