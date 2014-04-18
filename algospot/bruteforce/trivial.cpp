// http://algospot.com/judge/problem/read/BRUTEFORCE
#include <iostream>

using namespace std;

int from, to, range;

long long buffer [32];


void getInput() {
    cin >> from >> to >> range;
}


long long get(int n) {
}


void solve() {
    long long r = (long long)range;
    buffer[0] = 0;
    buffer[1] = r;

    int i;
    for (i = 2; i < 32; i++) {
        buffer[i] = (buffer [i-1] * buffer [i-1]) % 1000000007LL;
    }
    
    long long sss = 0;
    for (i = from; i <= to; i++) {
        int p = i;
        long long sum = 1;
        while (p) {
            int x = __builtin_ctz(p);
            sum = sum * buffer[x+1] % 1000000007LL;
            p &= p - 1;
        }
        sss = (sss + sum) % 1000000007LL;
    }
    if (sss < 0) sss += 1000000007LL;
        cout << sss << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
