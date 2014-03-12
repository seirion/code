// http://algospot.com/judge/problem/read/KOOGLE
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long double LOG_26;

int n;
int m;
vector<string> pw;

void getInput() {
    pw.clear();
    cin >> n;
    char b[10];
    gets(b);
    for (int i = 0; i < n; i++) {
        string s;
        getline(std::cin, s);
        pw.push_back(s);
    }

    sort(pw.begin(), pw.end());
}

long double getValue(int index) {
    int a(0), f(0);
    size_t s = pw[index].size();
    for (int i = 0; i < s; i++) {
        if (pw[index][i] >= 'a') a++;
        else f++;
    }
    return LOG_26 * a + f;
}


void solve() {
    int maxi = 0; // index
    long double maxv = getValue(0); // value

    for (int i = 1; i < n; i++) {
        long double v = getValue(i);
        if (maxv < v) {
            maxv = v;
            maxi = i;
        }
    }

    cout << pw[maxi] << endl;
}

int main() {
    LOG_26 = (long double)log10(26);
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
