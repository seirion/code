// https://code.google.com/codejam/contest/6254486/dashboard#s=p2
// Problem C. Coin Jam
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;
typedef unsigned int uint32;

int n, k;
string str;
long long ccc[11][33];
long long fig[11]; // figure
vector<long long> prime;

bool is_prime(int p) {
    for (int i = 0; i < prime.size(); i++) if (p % prime[i] == 0) return false;
    return true;
}

void calc() {
    for (int i = 2; i <= 10; i++) {
        ccc[i][0] = 1;
        for (int j = 1; j <= 32; j++) {
            ccc[i][j] = ccc[i][j-1] * i;
        }
    }

    prime.push_back(2);
    for (long long i = 3; i <= 3333334LL; i+=2) {
        if (is_prime(i)) prime.push_back(i);
    }
    cout << prime.size() << endl;
}

void to_string(uint32 num) {

    int size = n-2;
    for (int i = 0; i < size; i++) {
        str[i+1] = (num & (1 << i) ? '1' : '0');
    }
    reverse(str.begin(), str.end());
}

bool check() {
    for (int i = 2; i <= 10; i++) fig[i] = strtol(str.c_str(), 0, i);
    return false;
}

void solve() {
    cin >> n >> k;
    str.resize(n);
    str[0] = str[n-1] = '1';

    uint32 num = 0;
    const uint32 LIMIT = (1 << (n-2));

    int now = 0;
    while (now < k && num < LIMIT) {
        to_string(num);
        if (check()) {
            now++;
        }
        num++;
    }

    //cout << strtol(str.c_str(), 0, 3) << endl;
}

int main() {
    calc();

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d:\n", i);
        solve();
    }
}

