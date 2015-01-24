// http://codeforces.com/contest/507/problem/A
// A. Amr and Music
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Ins { public:
    Ins () {}
    int v, i;
    bool operator <(const Ins &ins) const {
        return v < ins.v;
    }
};

Ins ins[100];
int num, days;
int maxi = 0;

int main() {
    scanf("%d %d", &num, &days);
    int i;
    for (i = 0; i < num; i++) {
        scanf("%d", &ins[i].v);
        ins[i].i = i + 1;
    }
    sort(ins, ins+num);

    int c = 0;
    int sum = 0;
    vector<int> solution;

    for (i = 0; i < num; i++) {
        if (sum + ins[i].v <= days) {
            solution.push_back(ins[i].i);
            sum += ins[i].v;
        }
        else break;
    }
    printf("%d\n", solution.size());
    for (i = 0; i < solution.size(); i++) {
        printf("%d ", solution[i]);
    }
    printf("\n");
    return 0;
}
