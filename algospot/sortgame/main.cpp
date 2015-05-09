// http://algospot.com/judge/problem/read/SORTGAME
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int in[8];
map<vector<int>, int> memo;

vector<int> normalize() {
    vector<int> v;

    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (in[i] > in[j]) c++;
        }
        v.push_back(c);
    }

    return v;
}

void pre_process(int n) {
    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }

    queue<vector<int> > Q;
    Q.push(perm);
    memo[perm] = 0;

    while (!Q.empty()) {
        vector<int> now = Q.front(); Q.pop();
        int num = memo[now];

        for (int from = 0; from < n; from++) {
            for (int to = from+2; to <= n; to++) {
                reverse(now.begin() + from, now.begin() + to);
                if (memo.find(now) == memo.end()) { // not found
                    memo[now] = num + 1;
                    Q.push(now);
                }
                reverse(now.begin() + from, now.begin() + to); // restore
            }
        }
    }
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
}

void solve() {
    pre_process(n);
    auto v = normalize();
    printf("%d\n", memo[v]);
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
