// https://www.facebook.com/hackercup/problem/881509321917182/
// Facebook Hacker Cup 2016 Qualification Round
// The Price is Correct
#include <iostream>
#include <cstdio>

using namespace std;

int n, p;
long long in[100001];

void input() {
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    in[n] = 10000000000LL;
}

void solve(int k) {
    long long result = 0;
    long long sum = in[0];
    int begin(0), end(1); // [begin, end)

    while (begin < n) {
        if (sum == 0) {
            sum = in[begin];
            end = begin + 1;
        }
        if (p < sum) {
            sum = 0;
            begin++;
        }
        else {
            while (sum + in[end] <= p) {
                sum += in[end++];
            }
            result += (end - begin);
            sum -= in[begin++];
        }
    }

    printf("Case #%d: %lld\n", k, result);
}

int main() {
    int c; cin >> c;
    for (int i = 1; i <= c; i++) {
        input();
        solve(i);
    }
    return 0;
}
