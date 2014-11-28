// http://algospot.com/judge/problem/read/BRAVE
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
 
using namespace std;
 
int N, M;
vector<int> *ss[100 * 1000 + 1];
 
void merge(int x, int y) {
    if (ss[x] == 0 && ss[y] == 0) {
        ss[x] = new vector<int>();
        ss[y] = ss[x];
        ss[x]->push_back(x);
        ss[x]->push_back(y);
    }
    else if (ss[x] == 0) {
        ss[x] = ss[y];
        ss[y]->push_back(x);
    }
    else if (ss[y] == 0) {
        ss[y] = ss[x];
        ss[x]->push_back(y);
    }
    else if (ss[x] != ss[y]) {
        ss[x]->insert(ss[x]->end(), ss[y]->begin(), ss[y]->end());
        vector<int> *temp = ss[y];
        vector<int>::const_iterator i = temp->begin();
        for (; i != temp->end(); i++) {
            ss[*i] = ss[x];
        }
        delete temp;
    }
}

void solve() {
    memset(ss, 0, sizeof(int *) * (100 * 1000 + 1));
    int i, x, y;
    scanf("%d %d", &N, &M);
    for (i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        merge(x, y);
    }

    int m = 0;
    for (i = 1; i <= N; i++) {
        if (ss[i]) m = max(m, (int)ss[i]->size());
    }
    printf("%d\n", m);

    set<vector<int> *> s;
    for (i = 1; i <= N; i++) { // release
        if (s.find(ss[i]) == s.end()) {
            s.insert(ss[i]);
            delete ss[i];
        } 
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve();
    }
}
