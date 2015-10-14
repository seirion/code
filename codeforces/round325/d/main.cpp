// codeforces round325
// http://codeforces.com/contest/586/problem/D
#include <cstdio>
#include <set>

using namespace std;

class Node { public:
    Node(int r_, int c_): r(r_), c(c_) {}
    int r, c;
    bool operator <(const Node &n) const {
        return (c == n.c ? r < n.r : c < n.c);
    }
};

char in[3][105];
int n, m;

void input() {
    scanf("%d %d\n", &n, &m);
    fgets(in[0], 105, stdin);
    fgets(in[1], 105, stdin);
    fgets(in[2], 105, stdin);

    in[0][n]   = in[1][n]   = in[2][n]   = '.';
    in[0][n+1] = in[1][n+1] = in[2][n+1] = '.';
    in[0][n+2] = in[1][n+2] = in[2][n+2] = '.';
    in[0][n+3] = in[1][n+3] = in[2][n+3] = '.';
}

bool possible() {
    set<Node> s;
    if (in[0][0] == 's') s.insert(Node(0, 0));
    else if (in[1][0] == 's') s.insert(Node(1, 0));
    else s.insert(Node(2, 0));

   if (in[s.begin()->r][1] != '.') return false;

   while (!s.empty()) {
       int r = s.begin()->r;
       int c = s.begin()->c;
       if (c >= n-1) return true;

       s.erase(s.begin());

       set<int> v;
       v.insert(max(r-1, 0));
       v.insert(r);
       v.insert(min(r+1, 2));
       for (int x : v) {
           if (in[x][c+1] == '.' && in[x][c+2] == '.' && in[x][c+3] == '.' && in[x][c+4] == '.')
               s.insert(Node(x, c+3));
       }
   }

   return false;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        input();
        printf("%s\n", possible() ? "YES" : "NO");
    }
    return 0;
}
