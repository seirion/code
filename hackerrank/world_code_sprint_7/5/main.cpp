// https://www.hackerrank.com/contests/world-codesprint-7/challenges/inverse-rmq
// Inverse RMQ
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, org;
vector<int> v, out;
map<int, int> k;
map<int, int> mm; // for count
map<int, vector<int>> m;

int pow2(int k) { // 2^k
    if (k == 0 || k == 1) return 1;
    return 1 << (k-1);
}

bool valid() {
    int num = 0;
    int ccc = 0;

    for (auto it = m.rbegin(); it != m.rend(); it++, num++) {

        if (it->second.size() != pow2(num)) return false;
        ccc += it->second.size();
    }
    return ccc == org;
}

void put(int index, int value) {
    while (index < n) {
        out[index] = value;
        index = index * 2;
    }
}

void fill() {
    int index = 1;
    for (auto it = m.rbegin(); it != m.rend(); it++) {
        auto &vv = it->second; 
        //sort(vv.begin(), vv.end());

        for (int x : vv) {
            put(index, x);
            index += 2;
        }
    }
}

int main() {
    cin >> org;
    n = org << 1;

    v.resize(n);
    out.resize(n);
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        mm[v[i]]++;
    }

    for (auto it : mm) {
        m[it.second].push_back(it.first);
    }

    if (!valid()) {
        cout << "NO\n";
        return 0;
    }

    fill();
    cout << "YES\n";
    for (int i = 1; i < n; i++) cout << out[i] << " ";
    cout << endl;
    return 0;
}
