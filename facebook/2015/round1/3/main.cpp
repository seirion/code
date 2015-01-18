// https://www.facebook.com/hackercup/problems.php?pid=688426044611322&round=344496159068801
// Facebook Hacker Cup 2015 Round 1
// 3. Winning at Sports
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

const int MOD = 1000000007;

class Pair { public:
    Pair(int a_, int b_) : a(a_), b(b_) {}
    int a, b;
    bool operator <(const Pair& p) const {
        if (a == p.a) return b < p.b;
        return a < p.a;
    }
};

int memo_free[2001][2001];
int memo_stress[2001][2001];


void make_free(set<Pair> &free) {
    set<Pair> temp;

    while (!free.empty()) {
        set<Pair>::const_iterator i = free.begin();
        for (; i != free.end(); i++) {
            int a = i->a;
            int b = i->b;
            if (a+1 <= 2000) {
                temp.insert(Pair(a+1, b));
                memo_free[a+1][b] = (memo_free[a+1][b] + memo_free[a][b]) % MOD;
            }
            if (a > b+1) {
                temp.insert(Pair(a, b+1));
                memo_free[a][b+1] = (memo_free[a][b+1] + memo_free[a][b]) % MOD;
            }
        }

        free.swap(temp);
        temp.clear();
    }
}

void make_stress(set<Pair> &stress) {
    set<Pair> temp;

    while (!stress.empty()) {
        set<Pair>::const_iterator i = stress.begin();
        for (; i != stress.end(); i++) {
            int a = i->a;
            int b = i->b;
            if (a+1 <= b) {
                temp.insert(Pair(a+1, b));
                memo_stress[a+1][b] = (memo_stress[a+1][b] + memo_stress[a][b]) % MOD;
            }
            if (b < 2000) {
                temp.insert(Pair(a, b+1));
                memo_stress[a][b+1] = (memo_stress[a][b+1] + memo_stress[a][b]) % MOD;
            }
        }

        stress.swap(temp);
        temp.clear();
    }
}

void make() {
    memset(memo_free, 0, sizeof(int) * 2001 * 2001);
    set<Pair> free;
    free.insert(Pair(1, 0));
    memo_free[1][0] = 1;
    make_free(free);

    memset(memo_stress, 0, sizeof(int) * 2001 * 2001);
    set<Pair> stress;
    stress.insert(Pair(0, 1));
    memo_stress[0][1] = 1;
    make_stress(stress);
}

void solve() {
    int A, B;
    scanf("%d-%d", &A, &B);
	printf("%d %d\n", memo_free[A][B], memo_stress[B][B]);
}

int main() {
    make();
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}

