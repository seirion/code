#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

enum { LEFT, TOP, RIGHT, BOTTOM, NUM };
const int SIZE = 3 * 10000 + 2;
int n;
map<int, int> w, h; // input caching
int in[SIZE][NUM]; // input caching
int board[2000][2000] = {0, };

inline void counting(map<int, int> &m) {
    int i = 0;
    for (auto &it: m) it.second = i++;
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &in[i][LEFT], &in[i][TOP], &in[i][RIGHT], &in[i][BOTTOM]);
        w[in[i][LEFT]] = w[in[i][RIGHT]] = 0;
        h[in[i][TOP]] = h[in[i][BOTTOM]] = 0;
    }
    counting(w);
    counting(h);
    for (int i = 0; i < n; i++) {
        in[i][LEFT] = w.find(in[i][LEFT])->second;
        in[i][RIGHT] = w.find(in[i][RIGHT])->second;
        in[i][TOP] = h.find(in[i][TOP])->second;
        in[i][BOTTOM] = h.find(in[i][BOTTOM])->second;
    }
}

// brute-force
void solve() {
    vector<bool> result;
    for (int i = n - 1; i >= 0; i--) {
        bool showing = false;
        for (int a = in[i][LEFT]; a <= in[i][RIGHT]; a++) {
            for (int b = in[i][TOP]; b <= in[i][BOTTOM]; b++) {
                if (board[a][b] == 0) {
                    board[a][b] = i;
                    showing = true;
                }
            }
        }
        result.push_back(showing);
    }
    for (auto it = result.rbegin(); it != result.rend(); it++) {
        if (*it) printf("true\n");
        else printf("false\n");
    }
}

int main() {
    input();
    solve();
    return 0;
}
