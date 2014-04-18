// http://algospot.com/judge/problem/read/BRUTEFORCE
#include <iostream>

using namespace std;
typedef long long int64;


int from, to, ratio;
int64 buffer [33];


void getInput() {
    cin >> from >> to >> ratio;
}

int64 powers(int n) {
    int64 sum = 1;
    while (n) {
        int x = __builtin_ctz(n);
        sum = sum * buffer[x+1] % 1000000007LL;
        n &= n - 1;
    }
    return sum;
}

void solve() {
    if (ratio == 1) {
        cout << (to - from + 1) % 1000000007LL << endl;
        return;
    }

    buffer[1] = (int64)ratio;

    int i;
    int limit = sizeof(int) * 8 - __builtin_clz(to) + 1;
    for (i = 2; i <= limit ; i++) {
        buffer[i] = (buffer [i-1] * buffer [i-1]) % 1000000007LL;
    }
    
    int64 a = powers(from);
    int64 b = powers(to - from + 1) - 1LL;
    int64 c = ratio - 1LL;

    int64 re = a * b;
    while (re % c) {
        re += 1000000007LL;
    }
    cout << (re / c) % 1000000007LL << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
