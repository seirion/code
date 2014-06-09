// http://algospot.com/judge/problem/read/YULO
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n;
int in[40];

void getInput() {
    int s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        in[i] = s * 10;
    }
    sort(in, in + n);
}

void solve() {
    int maxi = 0;
    int size = n / 2;

    if (n % 2 != 0) maxi = in[size];

    for (int i = 0; i < size; i++) {
        maxi = max(maxi, (in[i] + in[n-i-1]) / 2);
    }

    printf("%d.%d\n", maxi / 10, maxi % 10);
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        getInput(); solve();
    }
    return 0;
}
