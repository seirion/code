// http://codeforces.com/contest/538/problem/A
// A. Cutting Banner
#include <iostream>
#include <string>

using namespace std;

int main() {
    string in;
    cin >> in;
    string code("CODEFORCES");

    int size = code.size();
    if (in.size() < size) goto NO_ANSWER;
    for (int i = 0; i <= size; i++) {
        string s = in.substr(0, i) + in.substr(in.size() - size + i, size - i);
        if (s == code) {
            cout << "YES" << endl; return 0;
        }
    }
NO_ANSWER:
    cout << "NO" << endl;
    return 0;
}
