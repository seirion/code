// http://algospot.com/judge/problem/read/DICTIONARY
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n;
char in[1000][21];
bool table[27][27];
bool visit[27];
vector<int> solution;

bool valid(char *a, char *b) {
    if (*a == 0) return true;
    if (*b == 0) return false;

    if (*a == *b) {
        return valid(a + 1, b + 1);
    }

    if (table[*b-'a'][*a-'a']) {
        return false;
    }
    table[*a-'a'][*b-'a'] = true;
    return true;
}


void dfs(int index) { // depth-first-search
    visit[index] = true;

    for (int i = 25; i >= 0; i--) {
        if (!visit[i] && table[index][i]) {
            dfs(i);
        }
    }
    solution.push_back(index);
}

void solve() {
    memset(table, 0, sizeof(bool) * 27 * 27);
    memset(visit, 0, sizeof(bool) * 27);
    solution.clear();

    scanf("%d\n", &n);

    int i, j;
    for (i = 0; i < n; i++) {
        gets(in[i]);
    }
    for (i = 1; i < n; i++) {
        if (!valid(in[i-1], in[i])) {
            printf("INVALID HYPOTHESIS\n");
            return;
        }
    }

    for (i = 25; i >= 0; i--) {
        if (!visit[i]) {
            dfs(i);
        }
    }

    const char *DICT = "abcdefghijklmnopqrstuvwxyz";

    for (i = 25; i >= 0; i--) {
        printf("%c", DICT[solution[i]]);
    }
    printf("\n");

}

int main() {
    int num;
    scanf("%d\n", &num);
    for (int i = 0; i < num; i++) { solve();}
    return 0;
}
