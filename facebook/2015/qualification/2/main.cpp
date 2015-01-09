// https://www.facebook.com/hackercup/problems.php?pid=1036037553088752&round=742632349177460
// Facebook Hacker Cup 2015 Qualification Round
// #2. New Year's Resolution
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

int A, B, C, n; // input
int in[20][3];

bool balanced(int a, int b, int c) {
    return ((A*b) == (a*B) && (A*c) == (a*C));
}

bool test(int index, int a, int b, int c) {
    if (a != 0 && b != 0 && c != 0) {
        if (balanced(a, b, c)) return true;
    }
    if (index == n) return false;
    if (test(index + 1, a, b, c)) return true; // not eat
    return test(index + 1,
        a + in[index][0], b +in[index][1], c + in[index][2]); // eat
}

bool possible() {
    scanf("%d %d %d", &A, &B, &C);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &in[i][0], &in[i][1], &in[i][2]);
    }
    if (test(1, 0, 0, 0)) return true; // not eat
    return test(1, in[0][0], in[0][1], in[0][2]); // eat
}

int main() {
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        printf("Case #%d: %s\n", i+1, possible() ? "yes" : "no");
    }
}

