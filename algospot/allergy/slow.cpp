// https://www.algospot.com/judge/problem/read/ALLERGY
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
 
using namespace std;
 
typedef unsigned long long uint64;
int n, m;
uint64 g[51];
int sol; // solution
 
void input() {
    memset(g, 0, sizeof(uint64) * 51);
    int i;
    cin >> n >> m;
    map<string, int> mm; // name table
    for (i = 0; i < n; i++) {
        string name;
        cin >> name;
        mm[name] = i;
    }
 
    for (i = 0; i < m; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            string name;
            cin >> name;
            g[i] |= (1LL << mm[name]);
        }
    }
}
 
void find(uint64 so_far, uint64 covered) {
    int count = __builtin_popcountll(so_far);
    if (count >= sol) return; // not promissing
    if (__builtin_popcountll(covered) == n) {
        sol = count;
        return;
    }
 
    for (int i = 0; i < m; i++) {
        if ((so_far & (1LL << i)) || ((covered | g[i]) == covered)) continue;
        find(so_far | (1LL << i), covered | g[i]);
    }
}
 
void solve() {
    sol = 0x7FFFFFFF;
    find(0, 0);
    cout << sol << endl;
}
 
int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
