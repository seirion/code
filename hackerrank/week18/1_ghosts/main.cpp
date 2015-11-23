// https://www.hackerrank.com/contests/w18/challenges/ghosts
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    else return gcd(b, a%b);
}

bool ghost(int a, int b, int c, int d) {
    if (abs(a-b) % 3) return false;
    if ((b+c) % 5) return false;
    if (a*c % 4) return false;
    if (gcd(a, d) != 1) return false;
    return true;
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int num = 0;
    for (int a = 1; a <= A; a++) {
        for (int b = 1; b <= B; b++) {
            for (int c = 1; c <= C; c++) {
                for (int d = 1; d <= D; d++) {
                    if (ghost(a, b, c, d)) num++;
                }
            }
        }
    }
    cout << num << endl;
    return 0;
}
