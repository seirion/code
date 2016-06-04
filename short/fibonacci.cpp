#include <iostream>
#include <vector>

using namespace std;
typedef vector<long long> matrix;

long long memo[1001];

const int M = 1000000007;

matrix operator * (const matrix &a, const matrix &b) {
    matrix c(4);
    c[0] = (a[0] * b[0] + a[1] * b[2]) % M;
    c[1] = (a[0] * b[1] + a[1] * b[3]) % M;
    c[2] = (a[2] * b[0] + a[3] * b[2]) % M;
    c[3] = (a[2] * b[1] + a[3] * b[3]) % M;
    return c;
}

int fibonacci(int n) {
    if (n <= 1) return n;

    matrix r = {1, 0, 0, 1};
    matrix m = {1, 1, 1, 0};

    while (0 < n) {
        if (n & 1) {
            r = r * m;
        }
        m = m * m;
        n >>= 1;
    }

    return r[1];
}

int main() {
    memo[0] = 0; memo[1] = 1;
    for (int i = 2; i < 1001; i++) memo[i] = (memo[i-1] + memo[i-2]) % M;

    for (int i = 0; i < 1001; i++) {
        int x = fibonacci(i);
        cout << i << "\t" << memo[i] << "\t" << x << endl;
    }
}
