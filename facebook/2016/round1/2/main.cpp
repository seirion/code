// Facebook Hacker Cup 2016 Round 1
// Laundro, Matt
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

long long load, n, m, dry; // n: #washing, m: #dryer
long long in[100000];

void input() {
    cin >> load >> n >> m >> dry;
    for (int i = 0; i < n ; i++) cin >> in[i];
}

#define _pair pair<long long, long long>
void washing(vector<long long> &v) {
    priority_queue<_pair, vector<_pair>, greater<_pair> > Q;

    int i;
    for (i = 0; i < n; i++) {
        Q.push(make_pair(in[i], i));
    }

    for (i = 0; i < load; i++) {
        auto x = Q.top(); Q.pop();

        v[i] = x.first;
        x.first += in[x.second];
        Q.push(x);
    }
}

long long drying(const vector<long long> &v) {
    priority_queue<long long, vector<long long>, greater<long long> > Q;
    
    int i, j;
    for (i = 0; i < load && i < m; i++) {
        Q.push(v[i] + dry);
    }

    for (j = 1; j < load; j++, i++) {
        auto x = Q.top(); Q.pop();

        if (i < load) x = max(x, v[i]);
        x += dry;
        if (i < load) Q.push(x);
    }

    return Q.top();
}

void solve(int k) {
    vector<long long> v(load, 0); 
    washing(v);
    printf("Case #%d: %lld\n", k, drying(v));
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        input();
        solve(i);
    }
    return 0;
}

