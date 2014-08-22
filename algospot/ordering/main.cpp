// http://algospot.com/judge/problem/read/ORDERING
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <list>
#include <vector>

using namespace std;

int n, depnum;
bool checked[26];
set<int> gtable[26];


void getInput() {
    scanf("%d %d\n", &n, &depnum);
    int i;
    char a, b;
    for (i = 0; i < depnum; i++) {
        scanf("%c%c\n", &a, &b);
        gtable[b-'A'].insert(a-'A');
    }
}

void remove(int x) {
    for (int i = 0; i < n; i++) {
        gtable[i].erase(x);
    }
}

void solve() {
    memset(checked, 0, sizeof(bool) * 26);
    int i;
    list<int> r;
    vector<char> solution;
    for (i = 0; i < n; i++) { //init
        r.push_back(i);
    }

    while (!r.empty()) {
        list<int>::iterator it = r.begin();
        for (; it != r.end(); it++) {
            if (gtable[*it].empty()) {
                //solution.push_back((char)(*it + 'A'));
                cout << (char)(*it + 'A');
                remove(*it);
                r.erase(it);
                break;
            }
        }
    }

    cout << endl;

    for (i = 0; i < n; i++) {
        gtable[i].clear();
    }

    
}

int main(int, char *[]) {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
