// https://www.hackerrank.com/contests/code-cpp-september-2015/challenges/feighbours
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n;
int in[50001];
int out[50001];
vector<int> prime;
map<int, vector<int> > m;

bool is_prime(int p) {
    for (int i = 0; i < prime.size(); i++) {
        if (p % prime[i] == 0) return false;
    }   
    return true;
}

void make_prime() {
    prime.push_back(2);
    //for (int i = 3; i <= 3163; i+=2) {
    for (int i = 3; i <= 50000; i+=2) {
        if (is_prime(i)) prime.push_back(i);
    }
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in [i];
    }
}

void factorization() {
    for (int i = 0; i < n; i++) {
        int j(0), x(in[i]);
        while (j < prime.size()) {
            if (x % prime[j] == 0) {
                m[prime[j]].push_back(i);
                while (x % prime[j] == 0) x /= prime[j];
            }
            j++;
        }
        if (j == prime.size() && x != 1) m[x].push_back(i);
    }

#ifdef DEBUG
    for (auto &it : m) {
        cout << it.first << " :: ";
        for (auto x : it.second) {
            cout << x << " ";
        }
        cout << endl;
    }
#endif
}

void solve() {
    memset(out, 0xFF, sizeof(out));
    for (auto &it : m) {
        vector<int> &v = it.second;
        if (v.size() < 2) continue;
        int size = v.size() - 1;
        for (int i = 0; i < size; i++) {
            int &o = out[v[i]];
            if (o == -1 || v[i+1] < o) o = v[i+1];
        }
    }

    for (int i = 0; i < n; i++) {
        if (out[i] == -1) cout << out[i] << " ";
        else cout << out[i]+1 << " ";
    }
    cout << endl;
}

int main() {
    make_prime();
    input();
    factorization();
    solve();
    return 0;
}
