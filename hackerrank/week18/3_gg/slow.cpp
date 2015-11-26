// https://www.hackerrank.com/contests/w18/challenges/gg
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
char in[3002];
vector<int> v;

void print(const vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
        if (i+1 != v.size()) cout << (in[i] == 'G' ? "> " : "< ");
    }
    cout << "\n";
}

bool ok(const vector<int> &v) {
    for (int i = 0; i < n-1; i++) {
        if (in[i] == 'G') { // >
            if (v[i] < v[i+1]) return false;
        }
        else {
            if (v[i] > v[i+1]) return false;
        }
    }
    return true;
}

int main() {
    scanf("%d %d\n", &n, &m);
    fgets(in, sizeof(in), stdin);
    for (int i = 1; i <= n; i++) v.push_back(i);

    int ccc = 0;
    do {
        if (ok(v)) {
            //print(v);
            ccc++;
        }
    }
    while (next_permutation(v.begin(), v.end()));
    cout << ccc << endl;
    return 0;
}
