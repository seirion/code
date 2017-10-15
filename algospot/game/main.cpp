// http://algospot.com/judge/problem/read/GAME
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int n, k;
int in[500][501];
bool gone[500] = {false, };

void input() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) for (int j = 1; j <= k; j++) 
        scanf("%d", &in[i][j]);

    memset(gone, 0, sizeof(gone));
}

void solve() {
    for (int i = 1; i <= k; i++) {
        map<int, vector<int>> m;
        for (int j = 0; j < n; j++) {
            if (!gone[j]) {
                m[in[j][i]].push_back(j);
            }
        }

        auto it = m.begin();
        if (it->second.size() >= 2) {
            for (int i : it->second) printf("%d ", i+1); printf("\n");
            return;
        } else {
            gone[it->second.front()] = true;
        }
    }

    for (int j = 0; j < n; j++) {
        if (!gone[j]) printf("%d ", j+1);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {input(); solve();}
    return 0;
}
