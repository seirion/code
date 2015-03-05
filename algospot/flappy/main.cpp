// http://algospot.com/judge/problem/read/
#include <cstdio>
#include <set>

using namespace std;

class Node { public:
    Node (int rr, int cc, int ss) : r(rr), c(cc), s(ss) {}
    int r, c, s; // row, column, speed
    bool operator <(const Node &n) const {
        if (r == n.r) {
            if (c == n.c) return s < n.s;
            return c < n.c;
        }
        return r < n.r;
    }
};

int r, c;
char in [20][1000 + 1];

void input() {
    int i;
    scanf("%d %d\n", &r, &c);
    for (i = 0; i < r; i++) {
        gets(in[i]);
    }
}

void solve() {
    set<Node> s1, s2;
    for (int rr = 0; rr < r; rr++) {
        if (in[rr][0] == '@') {
            s1.insert(Node(rr, 0, 0));
            break;
        }
    }
    int score = 0;
    while (!s1.empty()) {

        set<Node>::const_iterator it = s1.begin();
        for (; it != s1.end(); it++) {
            Node n = *it;
            //printf(">>> %d %d %d\n", n.r, n.c, n.s);
            score = max(score, n.c);
            if (n.c == c || in[n.r][n.c] == '#') continue;
            s2.insert(Node(max(n.r-4, 0), n.c+1, 0)); // up
            if (n.r + n.s + 1 < r) {
                s2.insert(Node(n.r + n.s + 1, n.c+1, n.s+1)); // up
            }
        }
        s1.swap(s2); 
        s2.clear();
    }

    printf("%d\n", score);
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
