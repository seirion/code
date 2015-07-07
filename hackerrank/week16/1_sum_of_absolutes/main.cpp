// https://www.hackerrank.com/contests/w16/challenges/sum-of-absolutes
// Sum of Absolutes
#include <iostream>

using namespace std;

int N, Q;
int in[500002];

int main() {
    in[0] = 0;
    cin >> N >> Q >> in[1];
    for (int i = 2; i <= N; i++) {
        cin >> in[i];
        in[i] += in[i-1];
    }

    for (int i = 0; i < Q; i++) {
        int from, to;
        cin >> from >> to;
        cout << ((in[to] - in[from-1]) & 1 ? "Odd": "Even") << "\n";
    }

    return 0;
}
