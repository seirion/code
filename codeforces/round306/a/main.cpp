// http://codeforces.com/contest/550/problem/A
// A. Two Substrings
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
 
using namespace std;
 
char buffer[100000 + 2];
 
bool adj(const vector<int> &a, const vector<int> &b ) {
    for (int x : a) {
        for (int y : b) {
            if (abs(x - y) > 1) return false;
        }
    }
    return true;
}
 
int main() {
 
    fgets(buffer, 100000+2, stdin);
    int size = strlen(buffer) - 2;
 
    vector<int> a, b;
    for (int i = 0; i < size; i++) {
        if (buffer[i] == 'A' && buffer[i+1] == 'B') a.push_back(i);
        if (buffer[i] == 'B' && buffer[i+1] == 'A') b.push_back(i);
    }
 
    if (a.empty() || b.empty() || adj(a, b)) {
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;
    return 0;
}
