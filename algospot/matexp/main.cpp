// http://algospot.com/judge/problem/read/MATEXP
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define SIZE 100

int n, p;
int A[SIZE][SIZE];
int memo[20][SIZE][SIZE]; // F FFFF FFFF > 1,000,000

void getInput() {
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
}

void multi(int out[][SIZE], int in1[][SIZE], int in2[][SIZE]) {
    memset(out, 0, sizeof(int) * SIZE * SIZE);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                out[i][j] += (in1[i][k] * in2[k][j]);
                out[i][j] %= 10007;
            }
        }
    }
}

void print(int m[][SIZE]) {
    for (int i = 0; i < n; i++) {
        cout << m[i][0];
        for (int j = 1; j < n; j++) {
            cout << " " << m[i][j];
        }
        cout << endl;
    }
}

void solve() {
    int until = sizeof(int) * 8/*CHAR_BIT*/ - __builtin_clz(p);

    memcpy(memo, A, sizeof(int) * SIZE * SIZE);

    int i;
    for (i = 1; i <= until; i++) {
        multi(memo[i], memo[i-1], memo[i-1]); // A = A * A
    }

    int remain = p;
    int result[SIZE][SIZE];
    int temp[SIZE][SIZE];
    int index = __builtin_ctz(remain);
    remain &= remain - 1;
    memcpy(result, memo[index], sizeof(int)*SIZE*SIZE);
    memcpy(temp, result, sizeof(int)*SIZE*SIZE);
    while (remain) {
        index = __builtin_ctz(remain);
        remain &= remain - 1;
        multi(result, temp, memo[index]); // A = A * A
        memcpy(temp, result, sizeof(int)*SIZE*SIZE);
    }

    print(result);
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
