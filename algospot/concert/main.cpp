// http://algospot.com/judge/problem/read/CONCERT
#include <iostream>
#include <set>

using namespace std;

int n;
int vs;
int vm;
int v[50];
int solution;


void getInput() {
    cin >> n >> vs >> vm;
    for (int i = 0; i < n; i++) cin >> v[i];
}

void solve() {
    set<int> t1;
    set<int> t2;

    t1.insert(vs);

    for (int i = 0; i < n; i++) {
        set<int>::iterator it = t1.begin();
        for (; it != t1.end(); it++) {
            if ((*it) + v[i] <= vm) t2.insert((*it) + v[i]);
            if ((*it) - v[i] >= 0) t2.insert((*it) - v[i]);
        }

        t1.clear();
        t1.swap(t2);
    }

    if (t1.empty()) cout << -1 << endl;
    else cout << *t1.rbegin() << endl;
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {getInput(); solve();}
    return 0;
}
