// hyungyu.jang@lge.com
// problem 1

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int size;
char in[20]; // zero-base
bool temp [20][20]; // one-base
bool visit[20]; // one-base
vector<int> sol; // solution

const char *CHAR = "-123456789ABCDEF-";

void input() {
    memset(temp, 0, sizeof(bool) * 20 * 20);
    memset(visit, 0, sizeof(bool) * 20);
    sol.clear();
    gets(in + 1); // one-based

    // pre-process
    size = strlen(in + 1);
    for (int i = 1; i <= size; i++) {
        if (in[i] == '<') { temp[i][i+1] = true; }
        else { temp[i+1][i] = true; }
    }
    size++;
}

void dfs(int from) { // depth-first-search
    visit[from] = true;
    for (int to = size; to >= 1; to--) {
        if (!visit[to] && temp[from][to]) {
            dfs(to);
        }
    }
    sol.push_back(from);
}

void solve() {
    for (int i = size; i >= 1; i--) {
        if (!visit[i])
            dfs(i);
    }

    vector<int>::reverse_iterator it = sol.rbegin();
    for (; it != sol.rend(); it++) {
        printf("%c", CHAR[*it]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; i++) { input(); solve(); }
    return 0;
}

