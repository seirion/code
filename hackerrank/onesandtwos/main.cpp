// https://www.hackerrank.com/contests/mar14/challenges/ones-and-twos
#include <iostream>

using namespace std;

typedef long long int64;

int64 A, B;


void getInput() {
    cin >> A >> B;
}

int64 getC(int64 n) {
    if (n == 3) return 1;

    return getC(n-1) + getB(n-1);
}

int64 getB(int64 n) {
    if (n == 2) return 0;
    if (n == 3) return 1;

    return getB(n-1) + getB(n-2);
}

int64 getA(int64 n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;

    return (getA(n-1) + getB(n-1) + 2 * getC(n-1));
}

void solve() {
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
