// https://code.google.com/codejam/contest/6224486/dashboard#s=p2
// Problem C. Dijkstra

#include <cstdio>
#include <iostream>

using namespace std;

typedef long long int64;

char in[10002];

/**
 * 1 : 1, i : 2, j : 3, k : 4
 */
int table[5][5];
void make_table() {
    table[1][1] = 1; table[1][2] = 2; table[1][3] = 3; table[1][4] = 4; 
    table[2][1] = 2; table[2][2] = -1; table[2][3] = 4; table[2][4] = -3; 
    table[3][1] = 3; table[3][2] = -4; table[3][3] = -1; table[3][4] = 2; 
    table[4][1] = 4; table[4][2] = 3; table[4][3] = -2; table[4][4] = -1;
}

int multi(int a, int b) {
    int positive(1);
    if ((a >> 31) ^ (b >> 31)) positive = -1;
    //if ((a*b) < 0) positive = -1; // 다른 부호
    a = abs(a); b = abs(b);
    return positive * table[a][b];
}

bool solve() {
    int64 L, X;
    scanf("%lld %lld\n", &L, &X);
    fgets(in, 10002, stdin);

    bool exist_i(false), exist_j(false);
    int current(1); int64 i(0LL);
    for (i = 0; i < L; i++) {
        current = multi(current, in[i] - 'g');
        if (current == 2) exist_i = true;
        else if (exist_i && current == 4) exist_j = true;
    }

    if (current == 1) return false; // ijk 가 모두 포함될 수 없는 조건이다
    if (X == 1) { // 반복되지 않는다면, 이 안에 ijk 가 모두 있어야 함
        return (exist_i && exist_j && current == -1);
    }

    if (current == -1) {
        if (X % 2 != 1) return false;
    }
    else {
        if (X % 4 != 2) return false;
    }

    if (exist_i && exist_j) return true;
    const int64 LIMIT = L * min(X, 4 + (X % 4));
    for (; i < LIMIT; i++) {
        current = multi(current, in[i%L] - 'g');
        if (current == 2) exist_i = true;
        else if (exist_i && current == 4) return true;
    }

    return false;
}

int main() {
    make_table();

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: %s\n", i, solve() ? "YES" : "NO");
    }
}

