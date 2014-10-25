// http://algospot.com/judge/problem/read/FIX
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Problem {public:
    Problem(int i, int l) : index(i), level(l) {}
    int index, level;
    bool operator<(const Problem& p) const {
        return level < p.level;
    }
};

void solve() {
    int i, n, level;
    scanf("%d", &n);

    vector<Problem> problems;
    for (i = 0; i < n; i++) {
        scanf("%d", &level);
        problems.push_back(Problem(i, level));
    }
    sort(problems.begin(), problems.end());

    int count = 0;
    for (i = 0; i < problems.size(); i++) {
        if (i == problems[i].index) count++;
    }

    printf("%d\n", count);
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {solve();}
    return 0;
}
