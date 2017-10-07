// http://algospot.com/judge/problem/read/GGGCCCDDD
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

const int MOD = 1000000007;
int limit, loop, sum;
int g[1001][1001];

void input() {
    scanf("%d %d", &limit, &loop);
}

int gcd(int a, int b) {
    int &result = g[a][b]; 
    if (result == -1) {
        result = b ? gcd(b, a%b) : a;
    }
    return result;
}

void go(vector<int> &v) { // depth
    if (v.size() == loop) {
        auto it = v.begin();
        int res = *it; it++;
        while (it != v.end()) {
            res = gcd(res, *it);
            it++;
        }
        sum = (sum + res) % MOD;
        //cout << "     >    " << sum << endl;
        return;
    }

    for (int i = 1; i <= limit; i++) {
        v.push_back(i);
        go(v);
        v.pop_back();
    }
}

void solve() {
    memset(g, 0xFF, sizeof(g));
    sum = 0;
    vector<int> v;
    go(v);
    //cout << sum << endl;
}

int main() {
    /*
    int t;
    scanf("%d", &t);
    while (t--) {input(); solve();}
    */
    for (int i = 1; i <= 10; i++) {
        limit = i;
        for (int j = 1; j <= 10; j++) {
            loop = j;
            solve();
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
