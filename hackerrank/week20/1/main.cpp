// https://www.hackerrank.com/contests/w20/challenges/divisible-sum-pairs
// Divisible Sum Pairs
#include <iostream>

using namespace std;

int n, k;
int in[100];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    int r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if ((in[i] + in[j]) % k == 0) r++;
        }
    }
    cout << r << endl;
    return 0;
}
