// http://algospot.com/judge/problem/read/GGGCCCDDD
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

const int MOD = 1000000007;
long long limit, loop, sum;
long long g[1001][1001];
map<int, long long> m[1001], rr;

void input() {
    scanf("%d %d", &limit, &loop);
}

long long gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

void multiple() {
    for (int x = 1; x <= limit; x++) {
        for (int i = 1; i <= limit; i++) {
            m[x][gcd(i, x)]++;
        }
    }
}

void iterate() {
    map<int, long long> temp;

    for (int i = 1; i <= limit; i++) {
        int num = rr[i];
        for (auto &it : m[i]) {
            int gg = gcd(i, it.first);
            temp[gg] += num * it.second;
            temp[gg] = temp[gg] % MOD;
        }
    }

    rr.swap(temp);
    //for (int i = 1; i <= limit; i++) { cout << "    " << i << " " << rr[i] << endl; }
}

void clear() {
    for (int i = 1; i <= limit; i++) m[i].clear();
    rr.clear();
}

void solve() {
    multiple();
    for (int i = 1; i <= limit; i++) rr[i] = 1; // init

    while (--loop) iterate();

    long long sum = 0;
    for (auto &it : rr) {
        sum += (it.first * it.second) % MOD;
        sum = sum % MOD;
    }
    cout << sum << endl;
}

int main() {
    memset(g, 0xFF, sizeof(g));
    int t; cin >> t;
    while (t--) { input(); solve(); clear(); }
    return 0;
}
