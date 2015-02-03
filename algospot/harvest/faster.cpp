// http://algospot.com/judge/problem/read/HARVEST
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int row, col, n;
map <int, set<int> > mm;
map <int, int> value_to_index; // for fast indexing
set <int> col_index;

void input() {
    scanf("%d %d %d", &row, &col, &n);
    for (int i = 0; i < n; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        mm[r].insert(c);
        col_index.insert(c);
    }

    set<int>::const_iterator it = col_index.begin();
    for (int index = 0; it != col_index.end(); it++, index++) {
        value_to_index[*it] = index;
    }
}

void solve() {
    const int size = col_index.size();
    vector<int> memo;
    memo.push_back(size); // [)

    map <int, set<int> >::const_iterator ii = mm.begin();
    for (; ii != mm.end(); ii++) {
        const set<int> &ss = ii->second;

        set<int>::const_iterator cur = ss.begin();
        int i = 0;
        for (; cur != ss.end(); cur++) {
            int from = value_to_index[*cur];
            for (;; i++) {
                if (from < memo[i]) break;
            }
            memo[i] = from; 
            if (memo[i] == size) {
                memo.push_back(size);
            }
        }
    }

    printf("%d\n", memo.size() - 1);
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {input(); solve();}
    return 0;
}
