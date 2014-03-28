// 

#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
    #include <code/debug.h>
#else
    #define trace printf
#endif

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>

using namespace std;

///////////////////////////////////////////////////////////////////////
int n;
int count = 0; // finish condition
vector<string> in;
int result[1000] = {0, };

void getInput() {
    scanf("%d\n", &n);
    char buffer[1001];
    for (int i = 0; i < n; i++) {
        gets(buffer);
        in.push_back(string(buffer));
    }
}

void push(map<string, set<int> > &m, int length) {
    size_t s = in.size();
    for (int i = 0; i < s; i++) {
        //if (result[i]) continue;

        int to = in[i].size() - length;
        for (int j = 0; j <= to; j++) {
            string sub = in[i].substr(j, length);
            m[sub].insert(i);
        }
    }
}

void pop(map<string, set<int> > &m, int length) {

    map<string, set<int> >::iterator i = m.begin();
    for (; i != m.end(); i++) {
        if (i->second.size() == 1) {
            int index = *i->second.begin();
            if (result[index] == 0) {
                result[index] = length;
                count++;
            }
        }
    }

}

void solve() {
    map<string, set<int> > m; // map

    int len = 1; // from length 1
    while (count < n) {
        push(m, len);
        pop(m, len);

        len++;
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        trace("%d\n", result[i]);
    }
}


int main(int argc, char *argv[]) {
    getInput();
    solve();
    print();
    return 0;
}
