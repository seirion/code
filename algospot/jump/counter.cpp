// http://algospot.com/judge/problem/read/JUMP
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int n;
int out[1000];

void input() {
    scanf("%d", &n);
}

void solve() {
    memset(out, 0, sizeof(int) * 1000);
    set<pair<int, int> > mm, temp;
    int x(0), y(0);
    mm.insert(make_pair(x, y));
    for (int i = 1; i <= 10; i++) {
        for (auto m : mm) {
            x = m.first;
            y = m.second;

            temp.insert(make_pair(x, y+i));
            temp.insert(make_pair(x, y-i));
            temp.insert(make_pair(x+i, y));
            temp.insert(make_pair(x-i, y));
        }
        mm.swap(temp);
        temp.clear();
        printf("%d : %d\n", i, mm.size());
    }
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
