// http://algospot.com/judge/problem/read/ASYMTILING
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long int64;
int n;
int64 F[101];
int64 e[101];

int main() {
    int i;
    F[1] = 1;
    F[2] = 2;
    F[3] = 3;
    F[4] = 5;

    e[1] = 1;
    e[2] = 2;
    e[3] = 1;
    e[4] = 3;
    for (i = 5; i <= 100; i++) {
        F[i] = (F[i-1] + F[i-2]) % 1000000007LLU;
        e[i] = (e[i-2] + e[i-4]) % 1000000007LLU;
    }

    int num;
    cin >> num;
    for (i = 0; i < num; i++) {
        cin >> n;
        int64 ss = F[n] - e[n];
        if (ss < 0) ss += 1000000007LLU;
        printf("%llu\n", ss);
    }
    return 0;
}
