// http://algospot.com/judge/problem/read/WORDCHAIN
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <string>
#include <stack>

using namespace std;

int n;
int b[101][101];
stack<string> g[26][26];
vector<int> in, out;
vector<int> res; // output


void clear() {
    for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) stack<string>().swap(g[i][j]);
    memset(b, 0, sizeof(b));

    in.clear(); in.resize(26, 0);
    out.clear(); out.resize(26, 0);
    res.clear();
}

void input() {
    clear();
    scanf("%d", &n);
    int t = n;
    while (t--) {
        string s; cin >> s;
        int front = s.front() - 'a';
        int back = s.back() - 'a';

        g[front][back].push(s);
        b[front][back]++;
        out[front]++;
        in[back]++;
    }
}

void euler_circuit(int from) {
    for (int to = 0; to < 26; to++) {
        while (0 < b[from][to]) {
            b[from][to]--;
            euler_circuit(to);
        }
    }
    res.push_back(from);
}

void find() {
    for (int i = 0; i < 26; i++) {
        if (out[i] == in[i] + 1) {
            euler_circuit(i);
            return;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (0 < out[i]) {
            euler_circuit(i);
            return;
        }
    }
}

void solve() {
    find();

    if (res.size() != n + 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    auto aa = res.rbegin();
    auto bb = res.rbegin(); bb++;
    while (bb != res.rend()) {
        int from = *aa;
        int to = *bb;

        cout << g[from][to].top() << " ";
        g[from][to].pop();
        aa++; bb++;
    }
    cout << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {input(); solve();}
    return 0;
}
