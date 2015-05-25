// http://algospot.com/judge/problem/read/POPOWERWER
#include <cstdio>
#include <set>

using namespace std;

pair<int, int> p[11];

void pre() {
    p[2] = make_pair(2, 1);
    p[3] = make_pair(3, 1);
    p[4] = make_pair(2, 2);
    p[5] = make_pair(5, 1);
    p[6] = make_pair(6, 1);
    p[7] = make_pair(7, 1);
    p[8] = make_pair(2, 3);
    p[9] = make_pair(3, 2);
    p[10] = make_pair(10, 1);
}

pair<int, int> popowerwer(pair<int, int> pp, int b) {
    pp.second *= b;
    return pp;
}

void solve() {
    int a, b;
    scanf("%d %d", &a, &b);

    set<pair<int, int> > ss;
    for (int i = 2; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            ss.insert(popowerwer(p[i], j));
        }
    }
    printf("%d\n", ss.size() + 1); // 1 is default
}

int main() {
    pre();
    int t;
    scanf("%d", &t);
    while (t--) { solve(); }
    return 0;
}
